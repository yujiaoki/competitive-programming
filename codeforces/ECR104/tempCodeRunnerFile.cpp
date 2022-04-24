int BinarySearch(vector<ll> vec, int key) {
//     // key: 検索対象の値
//     int left = 0, right = vec.size(), mid;

//     while (left < right) {
//         mid = (left + right)/2;
//         if (vec[mid].first == key) {
//             return mid;
//         } else if (key < vec[mid].first) {
//             // 半分より下
//             right = mid;
//         } else if (vec[mid].first < key) {
//             // 半分より上
//             // 必要ないが，分かりやすいように条件を記述してある．
//             left = mid + 1;
//         }
//     }
//     // key が配列の中に見つからない場合
//     return -1;
// }