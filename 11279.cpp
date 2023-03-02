#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define FASTio ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl '\n' 

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

vector<int> heap;
int n,num,parent;
int lastindex = 0;

int main()
{
    FASTio;
    cin >> n;
    for(int i=0;i<n;i++)
    {   
        cin >> num;
        if(num==0)
        {
            if(heap.size()==0)
            {
                cout << 0 << '\n';
                continue;
            }
            else
            {   
                cout << heap[0] << '\n';
                lastindex--;
                heap[0] = heap[lastindex];
                heap.pop_back();
                int pos = 0;
                int parent;
                while(1)
                {   
                    int leftchild = pos*2+1;
                    int rightchild = pos*2+2;

                    // 자식이 없는경우
                    if(rightchild >= heap.size() && leftchild >= heap.size())
                    {   
                        break;
                    }

                    // 왼쪽자식뿐인경우 
                    else if(rightchild >= heap.size() && leftchild < heap.size())
                    {   
                        if(heap[leftchild] > heap[pos])
                        {
                            swap(heap[leftchild],heap[pos]);
                            break;
                        }

                        else
                        {
                            break;
                        }
                    }
                    // 왼쪽자식 오른쪽자식 둘다있는경우                    
                    else
                    {
                        if(heap[rightchild] > heap[leftchild] && heap[rightchild]<heap[pos])
                        { 
                        swap(heap[rightchild],heap[pos]);
                        pos = rightchild;
                        }
                        
                        else if(heap[rightchild] < heap[leftchild] && heap[leftchild]<heap[pos])
                        {
                        swap(heap[leftchild],heap[pos]);
                        pos = leftchild;
                        }

                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        else
        {
            heap.push_back(num);
            int pos = lastindex;

            while(1)
            {   
               if(pos==0) break;

               if(pos%2==0 && pos>0) parent = pos/2-1;
               else if(pos%2==1 && pos>0) parent = pos/2;
               
               if(heap[parent]>heap[pos])
                {swap(heap[parent],heap[pos]);}
               
               pos = parent;
            }
            lastindex++;
        }

    }
    return 0;
}