 int heapsort(int heap[], int no) 
 {
 	int i, j, root, c, temp;
 	int comparacoes=0;
 	
 	for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c])  
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j];   
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;    
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)   
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
            comparacoes++;
        } while (c < j);
    } 
    return comparacoes;
 }
 
    
    