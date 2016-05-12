MACRO(REQUIRED_THIRD target description targetName)
	OPTION("THIRD_${target}_DEV" "${description}" YES)
	SET("THIRD_${target}_NAME" ${targetName})
	SET("THIRD_${target}_SRC"
		"${CMAKE_SOURCE_DIR}/../" 
		CACHE PATH 
		"Path to extern project. Or can download with next option"
	)
	OPTION("THIRD_${target}_DOWNLOAD" "If THIRD_${target}_SRC doesn't set this is requried" YES)
ENDMACRO()
