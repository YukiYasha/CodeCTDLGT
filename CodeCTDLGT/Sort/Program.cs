using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sort
{
    class Program
    {
        private static void XuatMang(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write("{0}  ", arr[i]);
            }
            Console.WriteLine();
        }

        public static void swap(ref int x, ref int y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

        public static int min(int x, int y)
        {
            return (x > y) ? y : x;
        }

        public static int getMax(int[] arr)
        {
            int max = arr[0];
            for (int i = 1; i < arr.Length; i++)
                if (arr[i] > max)
                    max = arr[i];
            return max;
        }

        static void Main(string[] args)
        {
            Console.Write("Nhap so phan tu day so: ");
            int[] arr = new int[int.Parse(Console.ReadLine())];
            Random rd = new Random();

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rd.Next(-100, 100);
            }
            XuatMang(arr);

            //InterchangeSort(ref arr);
            //BubbleSort(ref arr);
            //ShakerSort(ref arr);
            //InsertionSort(ref arr);
            //SelectionSort(ref arr);
            //BinarySort(ref arr);

            //ShellSort(ref arr);

            //QuickSort(ref arr, 0, arr.Length - 1);
            //MergeSort(ref arr);
            //HeapSort(ref arr);

            //RadixSort(ref arr);

            Console.WriteLine("Day so da sap xep: ");
            XuatMang(arr);
            Console.ReadKey();
        }

        private static void InterchangeSort(ref int[] arr)
        {
            // Bắt đầu từ đầu dãy
            // Lấy từng p.tử so với những p.tử phía sau nó
            // Sau mỗi lần lặp tìm được min ở đầu dãy

            for (int i = 0; i < arr.Length; i++)
                for (int j = i + 1; j < arr.Length; j++)
                    if (arr[i] > arr[j])
                        swap(ref arr[i], ref arr[j]);
        }

        private static void BubbleSort(ref int[] arr)
        {
            // Bắt đầu từ cuối dãy
            // Lấy từng p.tử so với p.tử liền trước nó
            // Sau mỗi lần lặp tìm được min ở đầu dãy

            for (int i = 0; i < arr.Length - 1; i++)
                for (int j = arr.Length - 1; j > i; j--)
                    if (arr[j] < arr[j - 1])
                        swap(ref arr[j], ref arr[j - 1]);
        }

        private static void ShakerSort(ref int[] arr)
        {
            // Bắt đầu từ cả 2 đầu
            // Xử lý như BubbleSort từ cuối dãy đến đầu dãy tìm được min, lần sau bỏ qua min này
            // Xử lý như BubbleSort từ đầu dãy đến cuối dãy tìm được max, lần sau bỏ qua max này

            int left, right, k;

            left = 0;
            right = arr.Length - 1;
            k = arr.Length - 1;

            while (left < right)
            {
                for (int i = right; i > left; i--)
                    if (arr[i] < arr[i - 1])
                    {
                        swap(ref arr[i], ref arr[i - 1]);
                        k = i;
                    }

                left = k;

                for (int i = left; i < right; i++)
                    if (arr[i] > arr[i + 1])
                    {
                        swap(ref arr[i], ref arr[i + 1]);
                        k = i;
                    }

                right = k;
            }
        }

        private static void InsertionSort(ref int[] arr)
        {
            // Bắt đầu từ p.tử X = arr[1] vì coi như arr[0] đã được sắp xếp
            // So sánh X với các p.tử phía trước
            // Nếu nghịch thế thì bốc X ra, dời p.tử nghịch thế với X sang phải (vị trí của X)
            // Tiếp tục so X với các p.tử còn lại phía trước và dời đến khi nào hết nghịch thế thì chèn X vào

            int pos, x;
            for (int i = 1; i < arr.Length; i++)
            {
                x = arr[i];
                pos = i - 1;
                while ((pos >= 0) && (arr[pos] > x))
                {
                    arr[pos + 1] = arr[pos];
                    pos--;
                }
                arr[pos + 1] = x;
            }
        }

        private static void SelectionSort(ref int[] arr)
        {
            // Bắt đầu từ đầu dãy và xem p.tử đầu tiên là min
            // So sánh p.tử đó với các p.tử còn lại, nếu nghịch thế thì min = p.tử gây nghịch thế
            // Khi so sánh hết thì min là p.tử nhỏ nhất, tiến hành đổi chỗ min và p.tử xét ban đầu
            // Sau 1 lượt so sánh sẽ tìm được min đầu dãy và bỏ qua nó ở lần duyệt sau

            int min = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                min = i;
                for (int j = i + 1; j < arr.Length; j++)
                    if (arr[min] > arr[j])
                        min = j;

                swap(ref arr[i], ref arr[min]);
            }
        }

        private static void BinarySort(ref int[] arr)
        {
            // Bắt đầu từ p.tử X = arr[1] vì coi như đoạn arr[0] đã được sắp xếp
            // So sánh X với p.tử mid (chính giữa đoạn đã được sắp xếp)
            // Tùy vào KQ so sánh ta thu hẹp về phía trái || phải 1 nửa đoạn trên và so sánh X với mid của đoạn mới
            // Tiếp tục đến khi tìm vị trí chính xác, sau đó dời đoạn lớn hơn X rồi chèn X vào

            int left, right, mid;
            int x;
            for (int i = 1; i < arr.Length; i++)
            {
                x = arr[i];
                left = 0; // p.tử đầu của dãy đã được sắp xếp
                right = i - 1; // p.tử cuối của dãy đã được sắp xếp

                while (left <= right)
                {
                    mid = (left + right) / 2; // p.tử ở giữa đoạn đã được sắp xếp
                    // so sánh x với mid để tìm vị trí thích hợp chèn x
                    if (x < arr[mid])
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
                for (int j = i - 1; j >= left; j--)
                    arr[j + 1] = arr[j]; // dời các ptử > x  
                arr[left] = x;  // chèn x vào dãy
            }
        }

        private static void ShellSort(ref int[] arr)
        {
            int iM1 = (int)(Math.Log(arr.Length) / Math.Log(2));    // Số k khoảng cách
            double[] arrM1 = new double[iM1];

            arrM1[iM1 - 1] = 1;

            for (int z = iM1 - 2; z >= 0; z--)
            {
                arrM1[z] = 2 * arrM1[z + 1] + 1;    // 2h+1
            }

            int i, j, x, iLen;
            for (int iStep = 0; iStep < iM1; iStep++)
            {
                iLen = (int)arrM1[iStep];

                for (i = iLen; i < arr.Length; i++)
                {
                    x = arr[i];
                    j = i - iLen;
                    while ((x < arr[j]) && (j >= 0))
                    {
                        arr[j + iLen] = arr[j];
                        j = j - iLen;
                    }
                    arr[j + iLen] = x;
                }
            }
        }

        private static void QuickSort(ref int[] arr, int left, int right)
        {
            // Bắt đầu từ 2 đầu của dãy
            // So sánh đồng thời từng p.tử 2 đầu với p.tử ở giữa, dừng khi gặp nghịch thế
            // Đổi vị trí 2 p.tử nghịch thế với mid với nhau
            // Đệ quy xử lý công việc như trên cho 2 đoạn mới
            // từ đầu dãy đến p.tử nghịch thế sau mid
            // từ p.tử nghịch thế trước mid cho đến cuối dãy



            int i, j, mid;
            if (left >= right)
                return;
            mid = arr[(left + right) / 2];
            i = left; j = right;

            while (i < j)
            {
                while (arr[i] < mid) i++;
                while (arr[j] > mid) j--;
                if (i <= j)
                {
                    swap(ref arr[i], ref arr[j]);
                    i++; j--;
                }
            }

            QuickSort(ref arr, left, j);
            QuickSort(ref arr, i, right);
        }

        #region MergeSort
        private static void Distribute(int[] arr, ref int nb, ref int nc, int k, ref int[] brr, ref int[] crr)
        {
            int i, pa, pb, pc;
            pa = pb = pc = 0;

            while (pa < arr.Length)
            {
                for (i = 0; (pa < arr.Length) && (i < k); i++, pa++, pb++)
                    brr[pb] = arr[pa];

                for (i = 0; (pa < arr.Length) && (i < k); i++, pa++, pc++)
                    crr[pc] = arr[pa];
            }
            nb = pb;
            nc = pc;
        }
        private static void Merge(ref int[] arr, int nb, int nc, int k, ref int[] brr, ref int[] crr)
        {
            int p, pb, pc, ib, ic, kb, kc;
            p = pb = pc = 0;
            ib = ic = 0;

            while ((nb > 0) && (nc > 0))
            {
                kb = min(k, nb);
                kc = min(k, nc);

                if (brr[pb + ib] <= crr[pc + ic])
                {
                    arr[p++] = brr[pb + ib];
                    ib++;
                    if (ib == kb)
                    {
                        for (; ic < kc; ic++)
                            arr[p++] = crr[pc + ic];
                        pb += kb;
                        pc += kc;
                        ib = ic = 0;
                        nb -= kb;
                        nc -= kc;
                    }
                }
                else
                {
                    arr[p++] = crr[pc + ic];
                    ic++;
                    if (ic == kc)
                    {
                        for (; ib < kb; ib++)
                            arr[p++] = brr[pb + ib];
                        pb += kb;
                        pc += kc;
                        ib = ic = 0;
                        nb -= kb;
                        nc -= kc;
                    }
                }
            }
        }
        private static void MergeSort(ref int[] arr)
        {
            int[] brr = new int[arr.Length];
            int[] crr = new int[arr.Length];
            int k, nb = 0, nc = 0;

            for (k = 1; k < arr.Length; k *= 2)
            {
                Distribute(arr, ref nb, ref nc, k, ref brr, ref crr);
                Merge(ref arr, nb, nc, k, ref brr, ref crr);

                XuatMang(brr);
                XuatMang(crr);
                Console.ReadKey();
            }
        }
        #endregion

        #region HeapSort
        private static void Shift(ref int[] arr, int left, int right)
        {
            // Hiệu chỉnh đoạn left right thành heap

            int x, i, j;
            i = left;
            j = 2 * i + 1; // p.tử liên đới 2i
            x = arr[i];

            while (j <= right)
            {
                if (j < right)
                    if (arr[j] < arr[j + 1]) //tìm p.tử lớn hơn trong 2 p.tử liên đới 2i và 2i+1
                        j++; //lưu chỉ số p.tử liên đới lớn hơn

                if (arr[j] <= x) return;
                else
                {
                    arr[i] = arr[j];
                    arr[j] = x;
                    i = j;
                    j = 2 * i + 1;
                    x = arr[i];
                }
            }
        }
        private static void CreateHeap(ref int[] arr)
        {
            // Hiệu chỉnh dãy thành heap, bắt đầu từ giữa dãy
            int left = arr.Length / 2 - 1;

            while (left >= 0)
            {
                Shift(ref arr, left, arr.Length - 1);
                left--;
            }
        }
        private static void HeapSort(ref int[] arr)
        {
            int i;

            CreateHeap(ref arr);

            i = arr.Length - 1;
            while (i > 0)
            {
                swap(ref arr[0], ref arr[i]);
                i--;
                if (i > 0)
                    Shift(ref arr, 0, i);
            }
            
        }
        #endregion

        #region RadixSort
        // A function to do counting sort of arr[] according to 
        // the digit represented by exp. 
        private static void countSort(ref int[] arr, int exp)
        {
            int[] output = new int[arr.Length]; // output array 
            int i;
            int[] count = new int[10];

            // Store count of occurrences in count[] 
            for (i = 0; i < arr.Length; i++)
                count[(arr[i] / exp) % 10]++;

            // Change count[i] so that count[i] now contains actual 
            //  position of this digit in output[] 
            for (i = 1; i < 10; i++)
                count[i] += count[i - 1];

            // Build the output array 
            for (i = arr.Length - 1; i >= 0; i--)
            {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }

            // Copy the output array to arr[], so that arr[] now 
            // contains sorted numbers according to current digit 
            for (i = 0; i < arr.Length; i++)
                arr[i] = output[i];
        }

        // The main function to that sorts arr[] of size n using  
        // Radix Sort 
        private static void RadixSort(ref int[] arr)
        {
            // Find the maximum number to know number of digits 
            int m = getMax(arr);

            // Do counting sort for every digit. Note that instead 
            // of passing digit number, exp is passed. exp is 10^i 
            // where i is current digit number 
            for (int exp = 1; m / exp > 0; exp *= 10)
                countSort(ref arr, exp);
        }
        #endregion
    }
}
