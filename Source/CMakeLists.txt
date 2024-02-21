set(HEADERS
	"Core/Application.hpp"
	"Core/TextParser.hpp"
	"Core/Log.hpp"
	"Math/BasicMath.hpp"
	"Window/GLFWWindow.hpp"
)

set(SOURCES
	"Entry.cpp"	
	"Core/Application.cpp"
	"Core/TextParser.cpp"
	"Math/BasicMath.cpp"
	"Window/GLFWWindow.cpp"
)

target_sources(${PRJ_NAME} PUBLIC
	${HEADERS}
	${SOURCES}
)