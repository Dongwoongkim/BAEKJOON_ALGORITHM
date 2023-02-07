    // int sum = 0;
    // check[y][x] = true;

    // vector<vector<int>> visited(n+1,vector<int>(m+1,0));
    // vector<vector<bool>> check(n,vector<bool>(m+1,false));
    // queue <pair<int,int>> q;
        
    // q.push(make_pair(y,x));

    // while(!q.empty())
    // {   
    //     int y = q.front().first;
    //     int x = q.front().second;
    //     q.pop();

    //     if(1)
    //     {   
    //         sum += visited[y-1][x-1];
    //         break;
    //     }

    //     else
    //     {
    //         for(int k=0;k<4;k++)
    //         {
    //             int ny = y + dy[k];
    //             int nx = x + dx[k];

    //             if(ny>=0 && nx>=0 && ny<n && nx<m)
    //             {
    //                 if(area[ny][nx]!='x' && check[ny][nx]==false)
    //                 {   
    //                     check[ny][nx]=true;
    //                     q.push(make_pair(ny,nx));
    //                     visited[ny][nx] = visited[y][x]+1;
    //                 }
    //             }
    //         }
    //     }
    // }
