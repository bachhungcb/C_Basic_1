def check_identical_large_files(file_path1, file_path2):
    with open(file_path1, 'r') as f1, open(file_path2, 'r') as f2:
        for line_number, (line1, line2) in enumerate(zip(f1, f2), start=1):
            if line1 != line2:
                print(f"Line {line_number} is different.")
                print(f"Correct: {line1.strip()}")
                print(f"User: {line2.strip()}")
        else:
            print("The two files are identical.")

# Test the function with your file paths
file1 = r'D:\C Basic\testing file\correct.txt.txt'
file2 = r'D:\C Basic\testing file\user.txt.txt'

check_identical_large_files(file1, file2)
