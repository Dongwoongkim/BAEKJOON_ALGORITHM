if(k==1)
                {
                    d[i+1][0] = min(d[i+1][0], d[i][1] + v[i+1][0]);
                    d[i+1][2] = min(d[i+1][2], d[i][1] + v[i+1][2]);
                }
                if(k==2)
                {
                    d[i+1][0] = min(d[i+1][0], d[i][1] + v[i+1][0]);
                    d[i+1][1] = min(d[i+1][1], d[i][2] + v[i+1][1]);
                }