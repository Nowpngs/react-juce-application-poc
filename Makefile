install-dependencies:
	@echo "Installing Dependencies..."
	cd backend && cmake -S . -B build

build-plugin:
	@echo "Building Project..."
	cd backend && cmake --build build

run-plugin:
	@echo "Running Plugin..."
	@cd backend/build/app/ReactJuceGUIApplication_artefacts/ReactJuceGUIApplication.app/Contents/MacOS/ && ./ReactJuceGUIApplication

format-style:
	@echo "Formatting Code..."
	@cd backend && find app \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} +
	@echo "Done!"