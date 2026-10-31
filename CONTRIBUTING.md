# Building 3DEN Enhanced with HEMTT

This guide explains how to clone **3DEN Enhanced**, set up HEMTT in Visual Studio Code, build the mod, and test it locally in Arma 3.

## 1. Clone the Repository

Open a terminal and navigate to your preferred project directory.

```powershell
git clone https://github.com/R3voA3/3den-Enhanced.git
```

Open the cloned repository in Visual Studio Code:

```powershell
code 3den-Enhanced
```

## 2. Install HEMTT

Download and install HEMTT from the official website:

[HEMTT – Official Website](https://hemtt.dev/)

After installation, verify that HEMTT is available by running the following command in the VS Code terminal:

```powershell
hemtt --version
```

If a version number is displayed, HEMTT is installed correctly.

## 3. Create a Separate Branch for Your Changes

**All changes must be made in a separate Git branch. Never work directly on the `main` branch.**

Before starting any development work, create a new branch:

```powershell
git switch -c feature/name-of-your-change
```

Use a descriptive name that reflects the purpose of your changes.

Examples:

- `feature/new-editor-function`
- `fix/toolbar-bug`
- `improvement/ui-layout`

## 4. Use HEMTT in Visual Studio Code

Open the `3den-Enhanced` project in Visual Studio Code.

Open the integrated terminal:

**Terminal → New Terminal**

Make sure the terminal is running in the project's root directory.

HEMTT automatically detects the existing project configuration in `.hemtt/project.toml`.

## 5. Build the Mod

To compile 3DEN Enhanced, run the following command in the VS Code terminal:

```powershell
hemtt build
```

HEMTT handles the processing and binarization of the mod files.

After a successful build, the compiled mod can be found in:

```text
.hemttout/build/
```

## 6. Test the Mod

To launch Arma 3 with the configured mod environment, run:

```powershell
hemtt launch
```

HEMTT starts Arma 3 so you can test your changes directly.

Make sure to verify your changes in the Eden Editor and confirm that all new or modified features work as expected.

## 7. Create a Pull Request

**A Pull Request must only be created after all changes have been successfully built and tested locally.**

Follow this workflow:

1. Implement your changes in your dedicated branch.
2. Run `hemtt build` and ensure the build completes successfully.
3. Run `hemtt launch` and test your changes in Arma 3.
4. Commit your changes:

   ```powershell
   git add .
   git commit -m "Description of your changes"
   ```

5. Push your branch to the remote repository:

   ```powershell
   git push -u origin feature/name-of-your-change
   ```

6. Create a Pull Request on GitHub targeting the `main` branch.

The Pull Request should contain only successfully tested changes and provide a clear description of the modifications.
