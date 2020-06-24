#include "route_model.h"
#include <iostream>

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml) {
    // Create RouteModel nodes.
    int counter = 0;
    for (Model::Node node : this->Nodes()) {
        m_Nodes.emplace_back(Node(counter, this, node));
        counter++;
    }
    CreateNodeToRoadHashmap();
}

void RouteModel::CreateNodeToRoadHashmap(){
    for(const auto &road: RouteModel::Roads()){
        if(road.type != Model::Road::Type::Footway){
            for(int node_idx : Ways()[road.way].nodes){
                if(RouteModel::node_to_road.find(node_idx) == node_to_road.end()){
                    node_to_road[node_idx] = std::vector<const Model::Road*>();
                }
                node_to_road[node_idx].push_back(&road);
            }

        }

    }

}

RouteModel::Node *RouteModel::Node::FindNeighbor(std::vector<int> node_indices){
    Node *closest_node = nullptr;
    Node node;
    for(auto index: node_indices){
        node = parent_model->SNodes()[index];
        if(distance(node) != 0 && !node.visited){
            if(closest_node == nullptr || distance(node) < distance(*closest_node)){
                closest_node = &parent_model->SNodes()[index];
            }
        }

    }
    return closest_node;
}

void RouteModel::Node::FindNeighbors(){

    for(auto& road: parent_model->node_to_road[this->index]){
        Node* closest_node = FindNeighbor(parent_model->Ways()[road->way].nodes);
        if(closest_node != nullptr){
            this->neighbors.push_back(closest_node);
        }
    }
}


RouteModel::Node &RouteModel::FindClosestNode(float x, float y){
    RouteModel::Node input = RouteModel::Node();
    input.x = x;
    input.y = y;

    float min_dist = std::numeric_limits<float>::max();
    int closest_idx;
    float dist;
    for(auto const &road : Roads()){
        if(road.type != Model::Road::Type::Footway){   
            for(int node_idx : Ways()[road.way].nodes){
                dist = input.distance(SNodes()[node_idx]);
                if(min_dist > dist){
                    closest_idx = node_idx;
                    min_dist = dist;
                }
            }
        }
    }

    return SNodes()[closest_idx];

}




