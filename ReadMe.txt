Active-Directory Batch User Manager

program to simulate bulk active directory operations by reading a csv of username,action pairs (create, disable, delete) and logging each action with a timestamp.

Test run:

niaz,create
john,disable
robert,delete

Output:
Wed May 14 17:35:53 2025 Created user: niaz
Wed May 14 17:35:53 2025 Disabled user: john
Wed May 14 17:35:53 2025 Deleted user: robert
