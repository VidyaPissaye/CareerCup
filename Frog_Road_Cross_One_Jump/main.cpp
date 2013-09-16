/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on September 15, 2013, 10:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/*
 *  If there are N lanes and K cars in each lane and Cars[i][j] = (pos of car, length of car),
 *  A frog has to cross the road in one straight jump (vertically down), without encountering
 *  any car. Determine if the frog will be able to do so. The road is in frozen state.
 */

struct position {
    int pos;
    int length;
};

bool frogCrossingRoad(vector<vector<position> > car_position, int road_length) {
    vector<int> free_spots_on_road;
    
    int num_of_lanes = car_position.size();
    int num_of_cars = car_position[0].size();
    
    for(int i = 0; i < num_of_lanes; i++) {
        int free_spots_in_lane = 0;
        int all_ones = (1 << (road_length + 1)) - 1; // Set ones for the length of the road
        for(int j = 0; j < num_of_cars; j++) {
            // Set ones for the length of the car from MSB
            int num = (all_ones >> car_position[i][j].length) ^ all_ones;
            
            // and Right shift the ones to the position of the car 
            free_spots_in_lane |= num >> car_position[i][j].pos;
        }
        // Convert the bits to have ones in free spots
        free_spots_on_road.push_back(free_spots_in_lane ^ all_ones);
    }
    
    int free = free_spots_on_road[0];
    int spot = 1; 
    while(spot < free_spots_on_road.size() && free != 0) {
        free = free & free_spots_on_road[spot];
        spot++;
    }
    
    return(free != 0 ? true : false);
}

int main(int argc, char** argv) {
    position elements[] = {{2, 3}, {6, 3}, {3, 4}, {8, 2}, {0, 4}, {6, 2}};
    int lanes = 3;
    int num_of_cars = 2;
    int road_length = 10;
    
    vector<vector<position> > cars_on_lanes;
    
    int k = 0;
    for(int i = 0; i < lanes; i++) {
        vector<position> arr;
        cars_on_lanes.push_back(arr);
        for(int j = 0; j < num_of_cars; j++) {
            cars_on_lanes[i].push_back(elements[k++]);
        }
    }
    
    cout << frogCrossingRoad(cars_on_lanes, road_length);
}

