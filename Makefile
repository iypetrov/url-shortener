build:
	@g++ main.cpp -std=c++17 -Iinclude -o bin/main

run:
	@./bin/main

deploy:
	@ngrok http http://localhost:8080
