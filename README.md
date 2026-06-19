# 學生成績管理系統 (Student Performance Management System)

這是一個使用 C++ 實作的學生成績管理專題，主要應用了 STL 容器（vector）、STL 演算法（sort）以及 Template 函式。

## 檔案結構

* main.cpp: 系統主程式碼。
* README.md: 專案說明與環境設定指引。
* report.pdf: 自主學習與小專題報告。

## 編譯與執行方式

本專案需在支援C++17標準的環境下編譯。請開啟終端機並切換至專案根目錄，執行以下指令：

### 編譯指令
`g++ -std=c++17 main.cpp -o main`

### 執行指令
* **Windows 系統:** `.\main.exe`
* **Mac / Linux 系統:** `./main`

## 功能介紹
* Add student: 新增學生資料（包含學號重複防呆機制）。
* List all students: 列出所有學生的詳細資料。
* Sort by score: 將學生成績由高至低排序。
* Search by id: 透過學號快速查詢特定學生。
* Show statistics: 統計全班平均、最高分、最低分（使用 Template 實作）、以及及格與不及格人數。
