using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace List
{
    class Node
    {
        int Data;
        Node pNext;

        public Node() { }
        public Node(int Data, Node pNext)
        {
            this.Data = Data;
            this.pNext = pNext;
        }
    }
}
