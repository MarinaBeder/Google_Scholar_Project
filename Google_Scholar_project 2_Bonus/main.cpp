//COMPLEXITY FOR ALL PROJECT
//FOR general N^2=V^2
//FOR special our project E log(n)
//N -> REPRESENT VERTEX
//V -> REPRESENT EDGE
#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<pair<int,string>>v_nodes;
map <int, vector<int>> bonus;
int i=0,j=0;
int main()
{
    ifstream Nodes("nodes.csv");
    if(!Nodes.is_open())
    {
        cout<<"File cann't open"<<endl;
        return 0;


    }
    string paper_name;
    string line_nodes;
    /////////

    int id_paper;
    string id_string_paper;
    /////////////
    string line_edges;
    int id_cite;
    string id_string_cite;

//COMPLEXITY N WHERE N IS VERTEX
    while(getline( Nodes,line_nodes))
    {
        stringstream ss_nodes(line_nodes);
        getline( ss_nodes, id_string_paper,',');
        stringstream ss_id (id_string_paper);
        ss_id<<id_string_paper;
        ss_id>>id_paper;
        getline( ss_nodes, paper_name,',');
        v_nodes.push_back(make_pair(id_paper,paper_name));
        //v_result.push_back(make_pair(id_paper,0));
        //bouns[id_paper].push_back(0);




    }
    Nodes.close();


    //****************************************************************//
    set<pair <int,int> > edges;
    pair <int,int> pairs;

//COMPLXITY E log(N)
    int i=0;
    ifstream Edges("edges.csv");
    if(!Edges.is_open())
    {
        cout<<"File can't open"<<endl;
        return 0;
    }

    while(getline(Edges,line_edges))
    {
        stringstream ss_edges(line_edges);
        getline(ss_edges, id_string_paper,',');
        stringstream ss_id_paper (id_string_paper);
        ss_id_paper<<id_string_paper;
        ss_id_paper>>id_paper;

        getline(ss_edges,  id_string_cite,',');

        stringstream ss_id_cite ( id_string_cite);
        ss_id_cite<< id_string_cite;
        ss_id_cite>>id_cite;



       bonus[id_paper].push_back(id_cite);//COMPLIXITY LOG(N)


    }


    Edges.close();
///////////////////////////////////////////////////////////////////////////////////////////////////
    int id;
    cout<<"enter id: "<<endl;
    cin>>id;//(*ii).first
    map<int,int>count2;
    vector<int>v2;
    map<int, vector<int> >::iterator ii=bonus.begin();
    advance(ii, id);
    int x=0;

    //// general{(N-1)(N-1)=N^2=V^2},Special for our project{139*139=19321}
    vector <int> first_level = (*ii).second;
    for (unsigned j=0; j<first_level.size(); j++)//general{N-1},Special for our project{139}
    {
        map<int, vector<int> >::iterator ii2=bonus.begin();
        cout<<"iteration: "<<x<<endl;
        cout<<"-----------"<<endl;

        cout <<"Parent: "<<first_level[j] << " ";
        count2[first_level[j]]= -1;
        cout<<"Count_Parent: "<<count2[first_level[j]]<<" ";
        cout<<endl;
        advance(ii2, first_level[j]);
        vector <int> second_level = (*ii2).second;
        for (unsigned f=0; f<second_level.size(); f++)//general{N-1},Special for our project{139}
        {
            if(count2[second_level[f]]!=-1)
            {
                cout <<"Child: "<< second_level[f] << " ";
                count2[second_level[f]]+=1;
                cout<<"Count_Chiled: "<<count2[second_level[f]];

                cout<<endl;

            }
            else cout<< second_level[f]<<" "<<"we cannot add"<<endl;
        }
        cout<<endl;
        x++;
        cout<<"........................................................"<<endl;
    }
    cout<<endl;

    //COMPLEXITY N LOG(N)->Vlog(V)
    std::pair<int, int> Max_Recommendation;
    int maxValue = INT_MIN;

    for (const auto Recommendation: count2)
    {
        if (maxValue < Recommendation.second)
        {
            maxValue = Recommendation.second;
            Max_Recommendation = Recommendation;
        }
    }

    std::cout << "We Recommend you "<<endl;
    cout<<"paper id: "<<"[ "<<Max_Recommendation.first<<" ]"<<" which name is: "<<"{ "<<v_nodes[Max_Recommendation.first].second<<" }"<<endl;
    cout<<"Because the maximum count of cited of this paper is: "<<Max_Recommendation.second <<endl;

    /*
    for(int i=0; i<v_edges.size(); i++)
        {v_result[v_edges[i].first].second++;}//maximum is 139
        */

}

