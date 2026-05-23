# CPP

Repo này là nơi mình lưu lại các bài luyện lập trình C++ trong quá trình học thuật toán, giải bài trên các OJ và ôn tập các cấu trúc dữ liệu cơ bản. Nội dung chính là các lời giải độc lập, được sắp xếp theo chủ đề như quy hoạch động, cây đoạn, BFS, tìm kiếm nhị phân, cây và sắp xếp.

## Mục lục

- [Giới thiệu](#giới-thiệu)
- [Cấu trúc repo](#cấu-trúc-repo)
- [Chủ đề đang có](#chủ-đề-đang-có)
- [Cách chạy một bài C++](#cách-chạy-một-bài-c)
- [Quy ước trong code](#quy-ước-trong-code)
- [Gợi ý học theo repo](#gợi-ý-học-theo-repo)
- [Đóng góp và ghi chú](#đóng-góp-và-ghi-chú)

## Giới thiệu

Mục tiêu của repo:

- Lưu trữ lời giải C++ cho các bài luyện thuật toán.
- Gom các bài theo nhóm kiến thức để dễ ôn lại.
- Giữ lại một số template/hàm mẫu thường dùng khi làm bài.
- Theo dõi quá trình luyện tập qua từng chủ đề.

Repo phù hợp với những bạn đang học C++ và thuật toán ở mức nhập môn đến trung cấp, đặc biệt là khi muốn xem ví dụ lời giải ngắn gọn cho từng dạng bài.

## Cấu trúc repo

```text
CPP/
├── AILAB/                  # Một số thử nghiệm Python nhỏ
├── Func/                   # Hàm mẫu / thuật toán cơ bản
├── KTRA2/                  # Bài kiểm tra / bài nộp theo yêu cầu học phần
├── MARISAOJ/
│   ├── ATCODER_DP/         # Bài trong AtCoder Educational DP Contest
│   ├── BFS/                # Bài luyện BFS
│   ├── BINARYSEARCH/       # Bài luyện tìm kiếm nhị phân
│   ├── DP2/                # Bài luyện quy hoạch động
│   ├── OTHER/              # Bài lẻ / chủ đề khác
│   ├── SEGTREE/            # Bài luyện Segment Tree
│   ├── SORTING/            # Bài luyện sắp xếp
│   └── TREE/               # Bài luyện cây
├── ANS.md                  # Ghi chú / câu trả lời môn học
└── README.md               # Tài liệu giới thiệu repo
```

## Chủ đề đang có

| Thư mục | Nội dung | Số file C++ hiện có |
| --- | --- | ---: |
| `MARISAOJ/DP2` | Quy hoạch động, trạng thái thắng/thua, tối ưu trạng thái | 16 |
| `MARISAOJ/ATCODER_DP` | Các bài AtCoder DP như LCS, game, tree DP, interval DP | 8 |
| `MARISAOJ/SEGTREE` | Xây cây đoạn, truy vấn đoạn, cập nhật điểm | 7 |
| `MARISAOJ/BINARYSEARCH` | Tìm kiếm nhị phân trên đáp án / vị trí | 4 |
| `MARISAOJ/BFS` | Duyệt đồ thị/lưới bằng BFS | 3 |
| `MARISAOJ/OTHER` | Một số bài chưa phân loại rõ | 3 |
| `MARISAOJ/TREE` | Bài về cây, duyệt cây, xử lý quan hệ cha-con | 2 |
| `MARISAOJ/SORTING` | Bài sắp xếp | 1 |
| `Func` | Hàm mẫu, ví dụ như quicksort, gcd/lcm | 1 |
| `KTRA2` | Bài kiểm tra C++ | 6 |

Tên file trong `MARISAOJ` thường là mã bài hoặc tên bài trên OJ. Ví dụ:

- `MARISAOJ/DP2/145.cpp`
- `MARISAOJ/SEGTREE/SEGTREE.cpp`
- `MARISAOJ/ATCODER_DP/F.cpp`

## Cách chạy một bài C++

Mỗi file `.cpp` trong repo thường là một chương trình độc lập, có hàm `main()` riêng. Bạn có thể biên dịch và chạy từng file như sau.

### 1. Cài trình biên dịch

Trên macOS, có thể dùng Clang đi kèm Xcode Command Line Tools:

```bash
xcode-select --install
```

Kiểm tra:

```bash
c++ --version
```

### 2. Biên dịch một file

Ví dụ với bài Segment Tree:

```bash
c++ -std=c++17 -O2 -Wall MARISAOJ/SEGTREE/SEGTREE.cpp -o main
```

### 3. Chạy chương trình

Nhập dữ liệu trực tiếp:

```bash
./main
```

Hoặc chạy với file input:

```bash
./main < input.txt
```

Nếu muốn lưu output ra file:

```bash
./main < input.txt > output.txt
```

### 4. Ví dụ nhanh với quicksort

```bash
c++ -std=c++17 -O2 -Wall Func/quicksort.cpp -o quicksort
./quicksort
```

Input mẫu:

```text
5
4 1 5 2 3
```

Output:

```text
1 2 3 4 5
```

## Quy ước trong code

Một số file sử dụng phong cách thường gặp khi thi đấu lập trình:

- `cin.tie(nullptr)->sync_with_stdio(false);` để tăng tốc nhập/xuất.
- `typedef long long ll;` để viết ngắn kiểu số nguyên lớn.
- Macro như `pb`, `ff`, `ss`, `sz`, `allin` để code nhanh hơn.
- Mảng thường được đánh chỉ số từ `1` trong nhiều bài.
- Hằng số như `nmax` và `mod` được khai báo ở đầu file.

Ví dụ template hay xuất hiện:

```cpp
cin.tie(nullptr)->sync_with_stdio(false);
typedef long long ll;
#define endl '\n'
```

## Gợi ý học theo repo

Nếu bạn mới học thuật toán, có thể đi theo thứ tự sau:

1. `Func/` và `MARISAOJ/SORTING/`: ôn cú pháp C++, hàm, mảng, sắp xếp.
2. `MARISAOJ/BINARYSEARCH/`: luyện tư duy chia đôi và tìm kiếm trên đáp án.
3. `MARISAOJ/BFS/`: học duyệt đồ thị/lưới, hàng đợi, khoảng cách ngắn nhất không trọng số.
4. `MARISAOJ/DP2/`: luyện quy hoạch động cơ bản đến nâng cao hơn.
5. `MARISAOJ/SEGTREE/`: học truy vấn và cập nhật trên đoạn.
6. `MARISAOJ/TREE/`: luyện duyệt cây và xử lý dữ liệu dạng phân cấp.
7. `MARISAOJ/ATCODER_DP/`: tổng hợp nhiều dạng DP kinh điển.

Khi đọc một lời giải, nên tự trả lời các câu hỏi:

- Trạng thái hoặc cấu trúc dữ liệu chính là gì?
- Vì sao công thức chuyển trạng thái đúng?
- Độ phức tạp thời gian và bộ nhớ là bao nhiêu?
- Có trường hợp biên nào dễ sai không?
- Có thể viết lại lời giải ngắn hoặc rõ hơn không?

## Đóng góp và ghi chú

Repo này chủ yếu phục vụ mục đích học tập cá nhân. Nếu muốn phát triển tiếp, có thể bổ sung:

- File đề bài hoặc link đề bài cho từng lời giải.
- Ghi chú ngắn ở đầu mỗi file: ý tưởng, độ phức tạp, các case cần chú ý.
- Bộ test mẫu trong từng thư mục.
- Script build/chạy nhanh cho nhiều bài.
- Bảng theo dõi trạng thái: đã AC, cần tối ưu, cần viết lại.

## Tác giả

Repo được duy trì bởi [minh0824](https://github.com/minh0824).

Nếu repo này giúp bạn ôn lại một thuật toán hoặc hiểu thêm một cách giải, hãy thử tự code lại bài đó từ đầu. Đó thường là cách học chắc nhất.
