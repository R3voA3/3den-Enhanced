# Project Guidelines

3den Enhanced is an Arma 3 Eden Editor mod, primarily implemented in SQF with addon configuration, UI definitions, and localization. Keep changes focused and preserve compatibility with the game's editor and existing mission data.

## Repository Layout

- `addons/` contains the source packages for the mod:
  - `main/` is the primary addon. Its root contains addon metadata/config (`config.cpp`, `cfgPatches.hpp`), shared macros and definitions (`script_component.hpp`, `defineCtrls.inc`), and the main `stringtable.xml`.
    - `cfgFunctions/` holds SQF functions. Subfolders correspond to CfgFunctions categories; update `cfgFunctions/cfgFunctions.hpp` when adding a function.
    - `cfg3DEN/` holds Eden Editor configuration, including attribute definitions and control layouts (`attributesEditor/`, `attributesGroup/`, `attributesLayer/`, `attributesMarker/`, `attributesMission/`, `attributesObject/`, and shared `controls/`).
    - `display3DEN/` contains Eden display and menu-strip configuration.
    - `GUI/` contains definitions for the mod's custom dialogs and interfaces.
    - `data/` contains addon assets, organized into areas such as `fonts/`, `src/`, and `weapons/`.
  - `ace_arsenal_shortcut/`, `captureframeui/`, and `eventscripts/` are separate addon packages for their named integrations/features. Check each package's own config and source before changing its behavior.
- `optionals/` contains separately loadable optional addons, primarily to remove or alter specific features. Keep an optional change in its corresponding package rather than adding it to `main/`.
- `include/` contains Arma UI include files and macro definitions used by the addon configs.
- `.hemtt/` contains build configuration, lint rules, hooks, and the `missions/3denEnhanced.vr/` local Eden test mission. The mission's `.enh_eventScripts/` directory provides event-script test/setup code.
- `.hemttout/` is generated HEMTT output. Do not edit it; change source files and rebuild.
- `.github/` contains repository workflows and GitHub configuration. `.vscode/` contains workspace editor settings, tasks, and snippets.
- `3den-Enhanced.wiki/` is the documentation wiki submodule. Root `README.md`, `CONTRIBUTING.md`, `CHANGELOG.md`, and `CONTRIBUTORS.md` provide the project overview, developer workflow, release history, and credits.
- `images/` contains repository and documentation images. `python_code/` contains Python package/support files. `releases/` stores historical release archives; do not treat these as current build inputs.
- `.hemtt/project.toml` defines package identity, version, included files, and build/release options. `.hemtt/lints.toml` configures SQF and stringtable linting.
- See [CONTRIBUTING.md](CONTRIBUTING.md) for environment setup, branch workflow, building, launching, and pull requests. See [README.md](README.md) for the project overview and wiki link.

## Implementation Conventions

- Follow the existing SQF style: four-space indentation, `private` for local variables, descriptive `_camelCase` names, and `params` for function arguments.
- Include `#include "\x\enh\addons\main\script_component.hpp"` in main-addon SQF functions when following neighboring functions.
- Register each new main-addon function in the appropriate category in `addons/main/cfgFunctions/cfgFunctions.hpp`. The category's `file` path determines the function source location and `tag = "ENH"` determines its `ENH_fnc_` name.
- Prefer existing shared functions, macros, and UI controls over duplicating behavior. Keep control IDs, config paths, localization keys, and CfgFunctions names consistent with their declarations.
- Preserve existing attribute serialization and backward-compatibility behavior; attribute load/save handlers can affect saved mission data.
- Add user-visible text through the existing localization system rather than hard-coding it. Follow the relevant neighboring config and stringtable entries.
- The mod must run without CBA or any other third-party modification. Treat integrations as optional: guard config/API/extension access, provide a vanilla fallback where practical, and if a feature cannot work without the integration, disable only that feature gracefully with a clear notification or safe default. Do not make a third-party mod a requirement for the core addon. See the Pythia checks and graceful feature handling in `addons/main/cfgFunctions/3DENRPTViewer/fn_RPTViewer.sqf`, `addons/main/cfgFunctions/misc/fn_createBackupMissionSQM.sqf`, and `addons/main/cfgFunctions/3DENCommandPalette/fn_3DENCommandPalette_readJSONFile.sqf`.
- Keep SQF compatible with HEMTT lint rules. In particular, heed `.hemtt/lints.toml` command-case, banned-command, and all-caps-variable checks.
- Do not edit generated output under `.hemttout/`; change source files and let HEMTT regenerate build artifacts.

## Validation

- Run `hemtt check` after focused SQF or config changes.
- Run `hemtt build` when a change affects build output or before proposing a pull request.
- For behavior changes to Eden UI or editor events, also launch and verify in Arma 3 when available; `hemtt launch` uses the project's configured launch environment.
- Report validation that could not be run, including in-game verification when Arma 3 is unavailable.

## SQF Language Reference
For syntax and examples primarily use https://a3ref.github.io/ as reference. Only commands, functions and data type listed on this page exist in-game.
