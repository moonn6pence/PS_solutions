#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;
unordered_map<ll, ll> parent;

ll find(ll x){
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(ll x, ll y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    if (x > y){
        parent[y] = x;
    }
    else {
        parent[x] = y;
    }
}

void addNewRoom(ll k,ll room){

    parent[room] = room;

    if(room > 1 && parent.find(room - 1) != parent.end()){
        Union(room, room - 1);
    }

    if(room < k && parent.find(room + 1) != parent.end()){
        Union(room, room + 1);
    }
}

ll getNewRoom(ll k, ll room){
    ll newRoom = find(room) + 1;

    return newRoom;
}

ll assignRoom(ll k, ll room){
    if(parent.find(room) != parent.end()){
        room = getNewRoom(k, room);
        addNewRoom(k, room);
        return room;
    }

    addNewRoom(k, room);
    return room;
}

vector<ll> solve(ll k, vector<ll> room_number){
    vector<ll> result;

    for(auto iter : room_number){
        result.push_back(assignRoom(k, iter));
    }

    return result;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    answer = solve(k, room_number);
    return answer;
}