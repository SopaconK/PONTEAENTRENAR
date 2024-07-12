#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;


class Problem{
    public:
    lli id;
    vector<string> text;
    string src;
    bool done;
    Problem(lli _id, vector<string> _text, string _src, bool _done): id(_id), text(_text), src(_src), done(_done){}
};
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<Problem> lista;
map<lli,bool> mp; 

bool comp(Problem a, Problem b){
    return a.id<b.id;
}
void Insertar(){
     ifstream ArchivoE("insertproblem.xml");
    string line;
    string src;
    bool done;
    vector<string> txt;
    lli id;
    bool intxt=false;
    while (getline(ArchivoE, line))
    {
        if(intxt){
            if(line.find("</txt>")!=string::npos){
                intxt=false;
            }
            else{
                txt.pb(line);
            }
        }
        else if (line.find("<src>") != string::npos)         
        {
            src = line.substr(line.find(">") + 1, line.rfind("<") - line.find(">") - 1);
        }
        else if (line.find("<done>") != string::npos)
        {
            done = stoi(line.substr(line.find(">") + 1, line.rfind("<") - line.find(">") - 1));
        }
        else if (line.find("<txt>") != string::npos)
        {
            intxt=true;
          
        }
    }
    ArchivoE.close();
    
    id=rnd();
    id%=(1000000000000000);
    while(id<= 0 || mp[id]){
        id=rnd();
    }

    Problem aux (id,txt,src, done);
    lista.pb(aux);
    mp[id]=true;
    ifstream ArchivoO("problemas.xml");
    ofstream ArchivoS("temp.xml");
 while (getline(ArchivoO, line))
    {
        if (line.find("</problemas>") != string::npos)         
        {
           ArchivoS<<"<problem>"<<endl<<"<src>"<<src<<"</src>"<<endl<<"<done>"<<done<<"</done>"<<endl<<"<txt>"<<endl;
           for(string s: txt){
            ArchivoS<<s<<endl;
           }
           ArchivoS<<"</txt>"<<endl<<"<id>"<<id<<"</id>"<<endl<<"</problem>"<<endl<<line<<endl;
        }
       else{
            ArchivoS<<line<<endl;
       }
    }


    ArchivoO.close();
    ArchivoS.close();
    remove("problemas.xml");
    rename("temp.xml", "problemas.xml");
}


void GenerarListas(){
    
    cout<<"Que quieres hacer?"<<endl<<"1. Todos los problemas "<<endl<<"2. Los problemas no hechos"<<endl<<"3. Los problemas hechos"<<endl<<"4. Agregar Personalmente"<<endl;
    int type;
    cin>>type;
    string title="";
        string filename;
        cout<<"Dame el nombre del archivo (con .tex) "<<endl;
        cin>>filename;
        int nofword;
        cout<<"Numero de palabras del titulo"<<endl;
        cin>>nofword;
        while(nofword--){
            string aux;
            cin>>aux;
            title+=aux+" ";
        }
        vector<Problem> list;
    lli mostrarsrc;
    cout<<"Quieres mostrar la fuente?"<<endl<<"1. Vacio"<<endl<<"2. Pon la id"<<endl<<"3. Fuentes"<<endl<<"4.Fuentes aparte"<<endl;
    cin>>mostrarsrc;
    
    if(type==1){
        list=lista;
    }
    else if(type==2){
        for(Problem p: lista){
            if(!p.done){
                list.pb(p);
            }
        }
    }
    else if(type==3){
        for(Problem p: lista){
            if(p.done){
                list.pb(p);
            }
        }
    }
    else if(type==4){
        cout<<"Dame los id de los problemas, se detiene en 0"<<endl;
        lli id;
        do{
            cin>>id;
             for(Problem p: lista){
            if(p.id==id){
                list.pb(p);
            }
        }
        } while(id!=0);
    }

    if(type!=4){
        cout<<"Orden? (0 es random 1 es decreciente)"<<endl;
        lli ord;
        cin>>ord;
        if(ord==0){
            shuffle(list.begin(), list.end(), rnd);
        }
        else{
            sort(list.begin(), list.end(), comp);
        }
        ofstream ArchivoS ("list.txt");
        for(Problem p: list){
            ArchivoS<<p.id<<endl;
        }
        ArchivoS.close();
    }
    lli cant;
    if(type!=4){
        cout<<"Cuantos problemas quieres? (-1 es todos)"<<endl;
        cin>>cant;
        if(cant==-1){
            cant=list.size();
        }
        cant=min(cant, (lli) list.size());
        vector<Problem> temp;
        for(lli i=0; i<cant; ++i){
            temp.pb(list[i]);
        }
        list=temp;
    }
    filename="outpdf/"+filename;
    ifstream ArchivoE("template.tex");
    ofstream ArchivoS (filename);
    string line;
   string auxi1{92};
    string auxi2=auxi1;
    string auxi3=auxi1;
    string auxi4=auxi1;
    string auxi5=auxi1;
    auxi3+="begin{itemize}";
    auxi1+="begin{problem}";
    auxi2+="end{problem}";
    auxi4+="ref";
    auxi5+="title{";
    
    while(getline(ArchivoE, line)){
        if (line.find(auxi5) != string::npos){
            ArchivoS<<auxi5<<title<<"}"<<endl;
        }
        else if( line.find("\section{Problemas}") != string::npos){
            ArchivoS<<line<<endl;
            if(mostrarsrc==1){
                for(Problem p: list){
                    ArchivoS<<auxi1<<endl;
                    for(string s: p.text){
                        ArchivoS<<s<<endl;
                    }
                    ArchivoS<<auxi2<<endl;
                }
            }
            else if(mostrarsrc==2){
                for(Problem p: list){
                    ArchivoS<<auxi1<<"["<<p.id<<"]"<<endl;
                    for(string s: p.text){
                        ArchivoS<<s<<endl;
                    }
                    ArchivoS<<auxi2<<endl;
                }
            }
             else if(mostrarsrc==3){
                for(Problem p: list){
                    ArchivoS<<auxi1<<"["<<p.src<<"]"<<endl;
                    for(string s: p.text){
                        ArchivoS<<s<<endl;
                    }
                    ArchivoS<<auxi2<<endl;
                }
            }
             else if(mostrarsrc==4){
                for(Problem p: list){
                    ArchivoS<<auxi1;
                    ArchivoS<<(char) 92<<"label{"<<p.id<<"}"<<endl;
                    for(string s: p.text){
                        ArchivoS<<s<<endl;
                    }
                    ArchivoS<<auxi2<<endl;
                }
                ArchivoS<<(char) 92<<"section{Fuentes}"<<endl;
                ArchivoS<<auxi3<<endl;
                for(Problem p: list){
                    ArchivoS<<(char) 92<<"item "<<auxi4<<"{"<<p.id<<"} "<<p.src<<endl;
                }
                ArchivoS<<(char) 92<<"end{itemize}"<<endl;
            }
        }
        else{
            ArchivoS<<line<<endl;
        }
    }
    ArchivoE.close();
    ArchivoS.close();
}

int main(){
    
    
    ifstream ArchivoE("problemas.xml");
    string line;
    string src;
    bool done;
    vector<string> txt;
    lli id;
    bool intxt=false;
    while (getline(ArchivoE, line))
    {
        if(intxt){
            if(line.find("</txt>")!=string::npos){
                intxt=false;
            }
            else{
                txt.pb(line);
            }
        }
        else if (line.find("<src>") != string::npos)         
        {
            src = line.substr(line.find(">") + 1, line.rfind("<") - line.find(">") - 1);
        }
        else if (line.find("<done>") != string::npos)
        {
            done = stoi(line.substr(line.find(">") + 1, line.rfind("<") - line.find(">") - 1));
        }
        else if (line.find("<txt>") != string::npos)
        {
            intxt=true;
          
        }
        else if (line.find("<id>")!= string::npos){
            id=stoll(line.substr(line.find(">") + 1, line.rfind("<") - line.find(">") - 1));
            Problem aux (id,txt,src, done);
            lista.pb(aux);
            txt.clear();
            mp[id]=true;
        }
    }
    ArchivoE.close();
    int type;
    bool seguir=true;
    while(seguir){
        cout<<"Que quieres hacer?"<<endl<<"1. Agregar un nuevo problema (pon la info en insertproblem.xml)"<<endl<<"2. Hacer lista"<<endl<<"3.Ver fuente con id"<<endl<<"4.Terminar"<<endl;
        cin>>type;
        if(type==1){
            Insertar();
        }
        else if(type==2){
            GenerarListas();
        }
        else if(type==3){
            lli sid;
            cout<<"Dame la id"<<endl;
            cin>>sid;
            for(Problem p: lista ){
                if(p.id==sid){
                    cout<<p.src<<endl;
                }
            }
        }
        else{
            seguir=false;
        }
    }

}