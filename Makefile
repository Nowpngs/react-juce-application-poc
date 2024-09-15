install-backend:
	@echo "Installing Dependencies..."
	cd backend && cmake -S . -B build

run-backend:
	@echo "Building Project..."
	@cd backend && cmake --build build

	@echo "Running Plugin..."
	@cd backend/build/app/ReactJuceGUIApplication_artefacts/ReactJuceGUIApplication.app/Contents/MacOS/ && ./ReactJuceGUIApplication

install-frontend:
	@echo "Installing Dependencies..."
	@cd frontend && npm install

run-frontend:
	@echo "Running Frontend..."
	@cd frontend && npm start

format-style:
	@echo "Formatting Code..."
	@echo "Formatting Backend JUCE Code..."
	@cd backend && find app \( -name '*.cpp' -o -name '*.h' \) -exec clang-format -i {} +
	@echo "Formatting Frontend Code..."
	@cd frontend && npm run format
	@echo "Success!"