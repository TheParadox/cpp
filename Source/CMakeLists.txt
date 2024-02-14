set(HEADERS
	"Core/Application.hpp"
	"Core/TextParser.hpp"
	"Math/BasicMath.hpp"
)

set(SOURCES
	"Entry.cpp"	
	"Core/Application.cpp"
	"Core/TextParser.cpp"
	"Math/BasicMath.cpp"
)

target_sources(${PRJ_NAME} PUBLIC
	${HEADERS}
	${SOURCES}
)