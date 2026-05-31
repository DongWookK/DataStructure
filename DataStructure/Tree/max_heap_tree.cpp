#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Max Heap 이용한 priority queue 구현
*/

// 마지막에 추가하고, 상향식으로 루트까지 올라가며 바꾼다.
void push(vector<int>& heap, int val)
{
    heap.push_back(val);
    int32_t idx = heap.size() - 1;
    int32_t parent_idx = (idx - 1) / 2;
    while (parent_idx != 0)
    {
        if (heap[parent_idx] < heap[idx])
        {
            swap(heap[parent_idx], heap[idx]);
            parent_idx = idx;
        }
        else
        {
            break;
        }
    }
}

void pop(vector<int>& heap)
{
    // delete root, and insert last leaf node that index
    heap[0] = heap.back();
    heap.pop_back();

    int32_t i = 0;
    while (true) {
        int32_t largest = i; // 최초값 루트, 이후로는 왼쪽값일수도
        int32_t left_idx = 2 * i + 1;
        int32_t right_idx = 2 * i + 2;

        // 둘중에 더 큰 수로 스왑한다. (왼쪽, 오른쪽 우선이 아님을 주의)
        if (left_idx < heap.size() && heap[left_idx] > heap[largest])
            largest = left_idx;
        if (right_idx < heap.size() && heap[right_idx] > heap[largest])
            largest = right_idx;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else {
            break;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int32_t> heap;

    while (n--) {
        int x;
        cin >> x;
        if (x > 0) {
            push(heap, x);
        }
        else {
            pop(heap);
        }
    }
    return 0;
}