#include<iostream>
using namespace std;

template<typename T>

class MyRelation
{
    
    
    public:
    T *s1;
    T *s2;
    bool ref=false,sym=false,ants=false,tra=false;
    int **result;
    T *r;
    int n,m=-1,size;

    MyRelation(int a,int si)
    {
        n=a;
        s1=new T[n];
        inputSet();
		this->size=(2*si);
        r=new T[size];
        result=new int*[n];

        for(int i=0;i<n;i++)
        {
            result[i]=new int[n];
        }
        cout<<"enter your relation is : "<<endl;
        inputRelation();
        set01();
    }

    MyRelation(int a,int b,int size)
    {
        n=a;m=b;
        s1=new T[n];
        s2=new T[m];
		this->size=2*size;
        r=new T[size];
        result=new int*[n];
        for(int i=0;i<n;i++)
        {
            result[i]=new int[m];
        }
        
        inputSet();
        cout<<"enter your relation is "<<endl;
        inputRelation();
    }

    void set01()
    {
        //0-1 in matrix
        
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        	{
        		for(int k=0;k<size;k+=2)
        		{
        			if(s1[i]==r[k] && s1[j]==r[k+1])
                    {
        				result[i][j]=1;
                        break;
                    }
        			else
        				result[i][j]=0;
				}
			}
		}

    }
    
    void reflexive()
    {
        ref=true;
        for(int i=0;i<n;i++)
        {
                if(result[i][i]!=1)
                {
                    ref=false;
                    break;
                } 
        }    
        if(ref==false)
            cout<<"it is not a reflexive relation "<<endl;
        
        if(ref==true)
            cout<<"it is a reflexive relation "<<endl;
        
    }
    void symmetric()
    {
        sym=true;
        int copy1[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 copy1[i][j]=result[i][j];
            }
               

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(copy1[i][j]!=copy1[j][i])
                    {
                        sym=false;
                        break;
                    }     
                }  
            }
            if(!sym)
            	break;
        }
            if(sym==true)
            	cout<<"it is a symmetric relation "<<endl;
			
            else
                cout<<"it is not a symmetric relation "<<endl;
        
    }
    void antisymmetric()
    {
        ants=true;
        int copy1[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 copy1[i][j]=result[i][j];
            }
               

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(copy1[i][j]=copy1[j][i])
                    {
                        ants=false;
                        break;
                    }     
                }  
            }
            if(!ants)
            	break;
        }
            if(ants==true)
            	cout<<"it is a anti-symmetric relation "<<endl;
			
            else
                cout<<"it is not a anti-symmetric relation "<<endl;

    }

    void inputSet()
    {
        cout<<"Enter your first set"<<endl;
        for(int i=0;i<n;i++)
            cin>>s1[i];
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;)
            {
                if(s1[i]==s1[j])
                {
                    for(int k=j;k<n-1;k++)
                    {
                        s1[k]=s1[k+1];
                    }
                    n--;
                }
                else
                    j++;
            }
        }
        cout<<"Your one set is "<<endl;
        cout<<"{";
        for(int i=0;i<n;i++)
        {
            cout<<s1[i];
            if(i<n-1)
                cout<<",";
        }
        cout<<"}"<<endl;
        
        if(m>0)
        {
            cout<<"Enter your second set"<<endl;
            for(int i=0;i<m;i++)
                cin>>s2[i];
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;)
            {
                if(s1[i]==s1[j])
                {
                    for(int k=j;k<m-1;k++)
                    {
                        s2[k]=s2[k+1];
                    }
                    m--;
                }
                else
                    j++;
            }
        }
            cout<<"Your second set is "<<endl;
            cout<<"{";
            for(int i=0;i<m;i++)
            {
               cout<<s2[i];
               if(i<n-1)
                cout<<",";
            }
            cout<<"}"<<endl;
        }
    }

    void inputRelation()
    {
        for(int i=0;i<size;i++)
        {
                cin>>r[i];
        }
        cout<<"your relation is : ";
        display();
        cout<<endl;
    }
    
    void reflexiveClosure()
    {
        if(!ref)
        {
        	cout<<"Your reflexive closure of relation is: ";
            cout<<"{";
            for(int i=0;i<size;i+=2)
            {
                cout<<"("<<r[i]<<","<<r[i+1] <<"),";
            }
            for(int i=0;i<n;i++)
            {
                if(result[i][i]!=1)
                {
                    cout<<"("<<s1[i]<<","<<s1[i]<<")";
                    if(i<n-1)
                        cout<<",";
                } 
            }
            cout<<"}"<<endl;
        }
        else
        cout<<"No reflexive closure , Relation is reflexive "<<endl;
    }

    void symmetricClosure()
    {
        int copy1[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
            	copy1[i][j]=result[i][j];
			}
                
        }
        if(!sym)
        { 
        	cout<<"Your symmetric closure of relation is : ";
            cout<<"{";
            for(int i=0;i<size;i+=2)
            {
                    cout<<"("<<r[i]<<","<<r[i+1]<<"),";
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j && copy1[i][j]==1 && copy1[j][i]==0)
                    {
                        cout<<"("<<s1[j]<<","<<s1[i]<<")";
                        if(i<n-1)
                            cout<<",";
                        copy1[j][i]=1;
                    } 
                }
            }
            cout<<"}"<<endl;
        }
        else
            cout<<"No symmetric closure , Relation is symmetric "<<endl;
    }
    void equivalence()
    {
        if(ref && sym && tra)
            cout<<"It is an equivalence reletion "<<endl;
    
    	else
        cout<<"It is not an equivalence reletion "<<endl;
	}
    void display()
    {
        cout<<"{";
            for(int i=0;i<size;i+=2)
            {
                    cout<<"("<<r[i]<<","<<r[i+1]<<"),";
            }
            cout<<"}";
    }
    void transitive()
    {
        tra=true;
        int copy1[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                copy1[i][j]=result[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(copy1[i][j]==1)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(copy1[j][k]==1)
                        {
                            if(copy1[i][k]!=1)
                            {
                                tra=false;
                                break;
                            }
                        }
                    }
                }
                if(!tra)
                    break;
            }
            if(!tra)
                break;
        }
        if(tra)
            cout<<"It is a transitive relation "<<endl;
        else
            cout<<"It is not a transitive relation"<<endl;
    }


    void transitiveExtension()
    {
        int copy1[n][n];
        int copy2[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                copy1[i][j]=result[i][j];
                copy2[i][j]=result[i][j];            	
			}

        }

        if(!tra)
        {
        	cout<<"Your transitive closure of relation by transitive extension is: ";
            int z=0;
            while(z<n)
            {
                for(int i=0;i<n;i++)
                {
                for(int j=0;j<n;j++)
                {
                    if(copy1[i][j]==1)
                    {
                        for(int k=0;k<n;k++)
                        {
                            if(copy1[j][k]==1)
                            {
                                copy2[i][k]=1;
                            }
                        }
                    }
                }
                }
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                        copy1[i][j]=copy2[i][j];
                }
                z++;
            }
            cout<<"{";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(copy1[i][j]==1)
                        cout<<"("<<s1[i]<<","<<s1[j]<<"),";

                }
            }
            cout<<"}"<<endl;
        }
        else    
            cout<<"no transitive closure , It is a transitive relation : by transitive extension "<<endl;
    }


    void warshall()
    {
        int copy1[n][n];
        int copy2[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                copy1[i][j]=result[i][j];
                copy2[i][j]=result[i][j];            	
			}

        }

        if(!tra)
        {
            cout<<"your trsnsitive closure of relation by warshall algorithm is : ";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(copy1[j][i]==1)
                    {
                        for(int k=0;k<n;k++)
                        {
                            if(copy1[i][k]==1)
                            {
                                copy2[j][k]=1;
                            }
                        }
                    }
                }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    copy1[i][j]=copy2[i][j];
            }
            
            }

                        cout<<"{";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(copy1[i][j]==1)
                        cout<<"("<<s1[i]<<","<<s1[j]<<"),";

                }
            }
            cout<<"}"<<endl;
        }
        else 
            cout<<"no transitive closure , It is a transitive relation : by warshall algorithm "<<endl;

    }
    void partialOrder()
    {
        if(ref && ants && tra)
        cout<<"It is a Partial odering relation "<<endl;
        else
        cout<<"It is not a Partial odering relation "<<endl;
    }   
};


template<typename T>
void set(T a)
{	
    int choice,n,m,size;
    	cout<<"\t\t 1 for relation on a set "<<endl;
        cout<<"\t\t 2 for reletion between two set "<<endl;
        
        cout<<"Enter your choice : ";
        cin>>choice;
        
    switch(choice)
    {
    	case 1:
        {
        	cout<<"Enter the size of set : ";
            cin>>n;
            cout<<"Enter the size of relation :";
            cin>>size;
            MyRelation<T> a(n,size);
            a.reflexive();
            a.symmetric();
            a.antisymmetric();
            a.transitive();
            a.reflexiveClosure();
            a.symmetricClosure();
            a.warshall();
            cout<<endl;
            a.transitiveExtension();
            cout<<endl;
            a.equivalence();
            a.partialOrder();

        }
			break;
		
		case 2:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            cout<<"Enter the size of relation :";
            cin>>size;
            MyRelation<T> c(n,m,size);
            c.display();
		}
        	break;
			
		default :
			cout<<"Invalid choice "<<endl;
	}
}

int main()
{	
    int choice2;
    double a=5.0;
    string g="null";
    char h='n';
    do 
     {
     	cout<<"\nEnter 1 for int element in a set "<<endl;
        cout<<"enter 2 for character element in a set "<<endl;
        cout<<"enter 3 for double type element "<<endl;
        cout<<"enter 4 for string type element "<<endl;
        
        cout<<"Enter your type : ";
        cin>>choice2;
        switch(choice2)
        {
        	case 1:
        		set(choice2);
        		break;
        	case 2:
        		set(h);
        		break;
        	case 3:
        		set(a);
        		break;
        	case 4:
        		set(g);
        		break;
        		
        	default:
        			cout<<"Invalid choice"<<endl;
        		
		}
		
        cout<<"\nDo you want to continue y/n : ";
        cin>>h;
    
    }while(h=='y');
    return 0;
}

