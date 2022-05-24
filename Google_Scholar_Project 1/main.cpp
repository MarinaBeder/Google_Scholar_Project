//COMPLEXITY OF ALL PROGRAMME IS N->NODES =Nlog(N)
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>>v_nodes;//paper_id,paper_name
vector<pair<int,int>>v_edges ;////paper_id,cite_id
vector<pair<int,int>>v_result;//paper_id,count
int i=0,j=0;
//complexity (NlogN)
bool  Sort_Result(const pair<int,int> count1,
               const pair<int,int> count2)
{
    return (count1.second >count2.second);
}
int main()
{//complexit N
    ifstream Nodes("nodes.csv");
    if(!Nodes.is_open())
    {
        cout<<"File can't open"<<endl;
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
int i=0;
    while(getline(Nodes,line_nodes))
    {
        stringstream ss_nodes(line_nodes);
        getline(ss_nodes, id_string_paper,',');
        //to convert string to integr
        stringstream ss_id (id_string_paper);
        ss_id<<id_string_paper;
        ss_id>>id_paper;

        getline(ss_nodes, paper_name,',');
       v_nodes.push_back(make_pair(id_paper,paper_name));

        v_result.push_back(make_pair(id_paper,0));

//cout<<v_nodes[i].first<<' '<< v_nodes[i].second<<endl;



    }
    Nodes.close();
    //****************************************************************//


    ifstream Edges("edges.csv");
    if(!Edges.is_open())
    {
        cout<<"File cann't open"<<endl;
        return 0;
    }//COMPLXITY E
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
        v_edges.push_back(make_pair(id_paper,id_cite));
        //cout<<v_edges[i].first<<' '<< v_edges[i].second<<endl;

    }
  Edges.close();
    //****************************************************************/
    int counter=0;
//1->2
//3->2
//COMPLEXITY E
    for(int i=0; i<v_edges.size(); i++)
    {v_result[v_edges[i].second].second++;}


    sort(v_result.begin(), v_result.end(), Sort_Result);
int number;
cout<<"How many papers you want to be viewed in order ?"<<endl;
cout<<"-----------------------------------"<<endl;
    cin>>number;
    //COMPLEXITY N
    for(int i=0; i<number; i++)
    {

cout<< i+1 <<" "<<"paper id: "<<v_result[i].first<<" "<<"which name is: "
<<v_nodes[v_result[i].first].second<<" "<<
"number of cited paper "<< v_result[i].second<<endl;



    }
}

