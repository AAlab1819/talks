# How to Use Git Bash

Hi, this is Captain Liv speaking, and we'll learn how to use one of software developer's backbone: Git Bash!

To do your weekly submission and final project, I recommend using Git Bash to change your repository. Compared to Github for Windows, Git Bash is easy to learn yet hard to master, and there are a lot of tools that will help you in the future (like mastering bash commands of squashing unnecessary commits).

Also, by using Git Bash, you can publish a lot of files in one commit, instead of having 21 commits just to edit one README.md. If you have me as your supervisor, I'll fire you for having _that much_ unnecessary commits.

Oh, and one important thing: as I usually work with Linux more than Windows, the steps I've written might be lacking for Windows users. Anyone can improve this guide. **If your improvements are accepted, you will receive extra points**, so do your best!

## Installation
- Download and install [Git Bash](https://git-scm.com/downloads)
- Open Git Bash (it is recommended to add Git Bash into your PATH variables)
- Setup your username and email  
  ```
  git config --global user.name <your username here>
  git config --global user.email <your email here>
  ```

## Weekly Submission
- Open your repo, where you put your weekly submission
- On the right side, there's a green button named `Clone or download`. Copy the link.
- Clone your git repo by typing:
  ```sh
  git clone <copied link>
  ```
- Change your working directory into your repo:
  ```sh
  cd <repo name>
  ```
  This is why we should not use space in file and folder names. Buuut, if you already _did_ have spaces in your file or folder names, wrap the file or folder name in double quotes, or add a backslash before each space character **(only for UNIX users)**.
  ```sh
  cd "<repo name with spaces>"
  # or (only for UNIX users)
  cd this\ is\ a\ folder\ with\ spaces
  ```
- Create new folder according to the convention:
  ```sh
  mkdir Week##-<topic>
  ```
- Change your working directory to the newly-created folder:
  ```sh
  cd Week##-<topic>
  ```
- Create your README.md

  **for UNIX users**
  ```sh
  touch README.md
  ```
  **for loyal Windows users**
  ```sh
  type nul > README.md
  ```
- Now that the folder has existed, you can insert your source codes into the folder.
- Use your favorite text editor to edit your `README.md`. My editor is Sublime Text with these plugins: MarkdownEditing and MarkdownPreview, but you can definitely use the ol' plain Notepad if you want to. Here's a format you can follow:
```
# Week <week number>- <topic> by <your name here>

## [<Name of the problem>](<link to your solution>)

<thought process>
```
- Here's where you might realize you need to create `.gitignore`. If you recall, `.gitignore`s are used to tell Git to ignore files specified in `.gitignore`. To do so, follow the steps below:
  - Change your working directory to your repo
  - Create the `.gitignore` file. It's usually invisible from your explorer, so you'll probably need to show hidden files/folders _or_ a dedicated text editor to access it.
  - Open your `.gitignore` in your favorite text editor (or you can use Vim directly from Git Bash if you want to).
  - Insert every file/directory names you don't want to include in your repo. Remember, you can always use [glob patterns](https://en.wikipedia.org/wiki/Glob_(programming)). For example, if you're working with Code::Blocks, you might want to include these:
  ```
  ### CodeBlocks ###
  # specific to CodeBlocks IDE
  # ignore all files with extension .layout, .depend, and .cbp
  *.layout
  *.depend
  *.cbp
  # generated directories
  # ignore all files in directories bin/ and obj.
  bin/
  obj/
  ```
  You can look it up [here](https://github.com/github/gitignore) if you need additional templates for your project.
- After you've finished editing, tell Git tracks your new files by typing `git add .`. This will tell Git to track every file, except for ones you've specified in `.gitignore`. You can do this for multiple times before committing.
- Before commit, make sure you run `git pull` first. This will update your local files with the newest ones. If someone has created a new commit, you'll know!
- When you're sure, commit them! 
  ```sh
  git commit -m "<your message here>
  ```
  - If you feel like you've done a minor mistake, you can use `git commit --amend --no-edit`. This will update your last commit, but only use it _for minor edits_ like fixing typos.
- It's finally the time for your submission to air! Run `git push origin master`, fill in the username and password, and you're good to go.

GLHF!
