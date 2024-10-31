PROBLEM A

	Đây là một bài Knapsack cơ bản chỉ có 1 điều khác biệt là ta cần thêm 1 chiều để quản lý món đồ trên tay của tên trộm và đảo chiều QHD vì cân nặng của các món vật là quá lớn. 

PROBLEM B
	Ta có thể thấy N = 5000 nên ta có thể 2 for để tìm 2 số đầu tiên rồi sau đó xử lí 2 số còn lại sau.
 	Nếu ta có 1 mask1 gọi mask2 là mask được tạo ra bằng cách biến cái bit 1 của mask1 thành bit 0 và ngược lại.
  	Ví dụ mask1 = 10110 thì mask2 = 01001
   	Thì tất cả các mask & mask = 0 sẽ là mask2 và các con của nó và ta có thể dùng SOS để giải.

PROBLEM F
	
	Vừa nhìn vào ta có thể thấy đây là một bài toán MAXFLOW.

	Quan trọng là nếu build đồ thị theo kiểu thông thường thì độ phức tạp sẽ là T*N*N, quá nguy hiểm. Nên ta phải thay đổi góc nhìn một tí.

	Ở đây ta sẽ tạo ra các đỉnh A, B, C, AB, AC, BC, ABC để quản lý lượng công nhân muốn làm công trình A, lượng công nhân muốn làm công trình B, lượng công nhân muốn làm công trình C, lượng công nhân muốn làm công trình A và B, lượng công nhân vừa muốn làm công trình A và C…
	
	Bằng cách nối A và B vào AB, A và C vào AC… AB, AC, BC vào ABC ta sẽ có thể đảm bảo được tất cả công nhân đều làm tối đa 1 việc và sau đó ta cứ làm như thông thường.
	
	

PROBLEM I
	
	Ta sẽ tiếp cận bài toán này theo hướng tham lam.
	Đầu tiên, dùng chặt nhị phân tìm kiếm một giá trị LIM nhỏ nhất sao cho có 1 cách chia mà độ stress của tất cả các nút trong cây đều nhỏ hơn hoặc bằng LIM.
	Xét một đỉnh u nếu f[u] * siz[u] >= LIM thì chắn chắc u có thể trở thành đỉnh stress nhất.
	Ngược lại thì u không thể trở thành đỉnh stress (trong cây phải có 1 đỉnh >= LIM mà tất cả các đỉnh trong cây con góc u đề < LIM vậy nên ở ngoài cây con góc sẽ có 1 đỉnh có độ stress lớn hơn u).

*siz[u] là số đỉnh trong cây con gốc u.



