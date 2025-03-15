bài 1:
//Hai thuộc tính mong muốn của một hàm băm là:

//Tính đồng nhất (Uniformity) – Hàm băm nên phân phối giá trị băm một cách đồng đều trên toàn bộ không gian đầu ra, giúp giảm xung đột (collision) khi nhiều khóa khác nhau có cùng giá trị băm.

//Tính chống va chạm (Collision Resistance) – Rất khó để tìm hai đầu vào khác nhau nhưng cho cùng một giá trị băm, đảm bảo tính bảo mật và hiệu suất của hệ thống sử dụng hàm băm.

 bai 2:
     gia tri ham bam.
     key 12:
         (2(12)+5)mod11=(24+5)mod11=29mod11=7
        hash value = 7;
     key 44:
        (2(44)+5)mod11=(88+5)mod11=93mod11=5
        hash value = 5
     key 13:
         (2(13)+5)mod11=(26+5)mod11=31mod11=9
        hash value = 9
      key 88:
         (2(88)+5)mod11=(176+5)mod11=181mod11=5
        hash value = 5;
     key 23:
        (2(23)+5)mod11=(46+5)mod11=51mod11=7
        hash value = 7
     key 94:
        (2(94)+5)mod11=(188+5)mod11=193mod11=6
        hash value = 6
      key 11:
        (2(11)+5)mod11=(22+5)mod11=27mod11=5
        hash value = 5;
     key 39:
        (2(39)+5)mod11=(78+5)mod11=83mod11=6
        hash value = 6
     key 20:
        (2(20)+5)mod11=(40+5)mod11=45mod11=1
        hash value = 1
      key 16:
         (2(16)+5)mod11=(32+5)mod11=37mod11=4
        hash value = 4;
     key 5:
        (2(5)+5)mod11=(10+5)mod11=15mod11=4
        hash value = 4
Nếu có va chạm, ta tìm vị trí tiếp theo còn trống theo vòng tròn.
index       Stored Value
0       	11
1       	20
2       	39
3       	5
4       	16
5       	44
6       	94
7       	12
8	        88
9	        13
10      	-
