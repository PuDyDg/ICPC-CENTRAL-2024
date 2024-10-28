PROBLEM A

	Đây là một bài Knapsack cơ bản chỉ có 1 điều khác biệt là ta cần thêm 1 chiều để quản lý món đồ trên tay của tên trộm và đảo chiều QHD vì cân nặng của các món vật là quá lớn. 

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



