// script.js
// Hàm lưu dữ liệu của bảng vào localStorage
function saveTableData(tableId) {
	const table = document.getElementById(tableId);
	const rows = table.querySelectorAll("tbody tr");
	const tableData = [];

	rows.forEach(row => {
			const cells = row.querySelectorAll("td");
			const rowData = [];
			cells.forEach(cell => {
					rowData.push(cell.innerText);
			});
			tableData.push(rowData);
	});

	// Lưu dữ liệu vào localStorage
	localStorage.setItem(tableId, JSON.stringify(tableData));
	alert(`Dữ liệu của ${tableId} đã được lưu.`);
}

// Hàm tải dữ liệu đã lưu từ localStorage
function loadTableData(tableId) {
	const savedData = localStorage.getItem(tableId);
	if (savedData) {
			const tableData = JSON.parse(savedData);
			const table = document.getElementById(tableId);
			const tbody = table.querySelector("tbody");

			// Xóa tất cả các dòng cũ
			tbody.innerHTML = "";

			// Thêm lại dữ liệu từ localStorage
			tableData.forEach(rowData => {
					const row = document.createElement("tr");
					rowData.forEach(cellData => {
							const cell = document.createElement("td");
							cell.contentEditable = "true";
							cell.innerText = cellData;
							row.appendChild(cell);
					});
					tbody.appendChild(row);
			});
	}
}

// Khi trang tải xong, kiểm tra xem có dữ liệu nào đã lưu trong localStorage không
document.addEventListener("DOMContentLoaded", () => {
	loadTableData("table1");
	loadTableData("table2");
});
