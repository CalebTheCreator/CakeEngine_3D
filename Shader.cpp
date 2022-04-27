#include "Shader.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include "GameObject.h"
#include <string>
#include "Window.h"

/*std::string load_file(const std::string& _path)
{
	std::ifstream file(_path.c_str());
	if(!file.is_open()) throw std::runtime_error("Failed to open file");
	std::string rtn;

	while(!file.eof())
	{
		std::string line;
		std::getline(file, line);
		rtn += line + '\n';
	}
	return rtn;
}
*/

Shader::Shader(/*std::string& _vertPath, const std::string& _fragPath*/)
{
	CreateVertexShader();
	CreateFragmentShader();
	CreateProgramId();
	/**std::string contents = load_File(_vertPath)
	{
		GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		std::string contents = load_file(_vertPath);
		cont char* src = contenets.c_str();
		glShaderSource(vertexShaderId, 1, &src, NULL);
		glCompileShader(vertexShaderId);
		GLint success = 0;
		glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
		if(!success) throw std::runtime_error("Failed to compile vertex shader");
	}
	*/
}

Shader::Shader(ShaderType s)
{
	switch(s)
	{
	case Light_Key:
		vertexShaderSrc =
			"attribute vec3 in_Position;            " \
			"                                       " \
			"void main()                            " \
			"{                                      " \
			" gl_Position = vec4(in_Position, 1.0); " \
			"}                                      ";

		fragmentShaderSrc =
			"void main()                       " \
			"{                                 " \
			" gl_FragColor = vec4(0, 0, 1, 1); " \
			"}                                 ";

		break;

	case Diffuse:
		vertexShaderSrc =
			"varying vec3 v_Normal;					" \
			"varying vec3 v_FragPos;				" \
			"										" \
			"void main()							" \
			"{										" \
			" v_Normal = mat3(u_Model) * a_Normal;	" \
			" v_FragPos = vec3(u_Model * vec4(a_Position, 1.0));" \
			"}										";

		fragmentShaderSrc =
			"varying vec3 v_Normal;										" \
			"varying vec3 v_FragPos;									" \
			"															" \
			"void main()												" \
			"{															" \
			" vec3 lightPos = vec3(10, 10, 10);							" \
			" vec3 diffuseColor = vec3(1, 1, 1);						" \
			"															" \
			" vec3 N = normalize(v_Normal);								" \
			" vec3 lightDir = normalize(lightPos - v_FragPos);			" \
			" float diff = max(dot(N, lightDir), 0.0);					" \
			" vec3 diffuse = diffuseColor * diff;						" \
			"															" \
			" vec3 lighting = diffuse;									" \
			" gl_FragColor = vec4(lighting, 1) * tex;					" \
			"}															" \
			;

		break;

	case Specular:
		vertexShaderSrc =
			"#version 120\n													 " \
			"uniform mat4 u_Projection;                                       " \
			"uniform mat4 u_Model;                                            " \
			"attribute vec3 a_Position;                                       " \
			"attribute vec2 a_TexCoord;                                       " \
			"attribute vec3 a_Normal;										" \
			"varying vec2 v_TexCoord;                                         " \
			"                                                                 " \
			"varying vec3 v_Normal;											  " \
			"varying vec3 v_FragPos;										  " \
			"																  " \
			"void main()                                                      " \
			"{                                                                " \
			"  gl_Position = u_Projection * u_Model * vec4(a_Position, 1.0);  " \
			"  v_TexCoord = a_TexCoord;                                       " \
			"  v_Normal = mat3(u_Model) * a_Normal;                           " \
			"  v_FragPos = vec3(u_Model * vec4(a_Position, 1.0));             " \
			"}                                                                " \
			"                                                                 ";

		fragmentShaderSrc =
			"uniform sampler2D u_Texture;                       " \
			"varying vec2 v_TexCoord;                           " \
			"varying vec3 v_Normal;                             " \
			"varying vec3 v_FragPos;                            " \
			"						                            " \
			"uniform vec3 u_ViewPos;						    " \
			"uniform vec3 u_View;						        " \
			"													" \
			"void main()                                        " \
			"{                                                  " \
			"  vec4 tex = texture2D(u_Texture, v_TexCoord);     " \
			"													" \
			"  vec3 lightPos = vec3(10, 10, 10);				" \
			"  vec3 diffuseColor = vec3(1, 1, 1);				" \
			"  													" \
			"  vec3 N = normalize(v_Normal);				    " \
			"  vec3 lightDir = normalize(lightPos - v_FragPos);	" \
			"  float diff = max(dot(N, lightDir), 0.0);			" \
			"  vec3 diffuse = diffuseColor * diff;				" \
			"													" \
			"  vec3 specularColor = vec3(1, 1, 1);				" \
			"  vec3 viewPos = vec3(0, 0, 0);					" \
			"  vec3 viewDir = normalize(viewPos - v_FragPos);	" \
			"  vec3 reflectDir = reflect(-lightDir, N);         " \
			"  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);" \
			"  vec3 specular = spec * specularColor;			" \
			"													" \
			"  vec3 lighting = diffuse + specular;				" \
			"  gl_FragColor = vec4(lighting, 1) * tex;		" \
			"}                                                  " \
			"                                                   ";

		break;
	}

	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderId);
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(vertexShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile vertex shader");
	}

	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(fragmentShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile fragment shader");
	}

	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "a_Position");
	glBindAttribLocation(programId, 1, "a_TexCoord");
	glBindAttribLocation(programId, 2, "a_Normal");

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(programId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(programId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to link shader program");
	}

	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}

Shader::Shader(ShaderType sT, GameObject g)
{
	int x = g.GetPosition().x;
	int y = g.GetPosition().y;
	int z = g.GetPosition().z;
	std::string strX = std::to_string(x);
	std::string strY = std::to_string(y);
	std::string strZ = std::to_string(z);
	//attribute vec3 a_Position = vec3(" + strX + "," + strY + "," + strZ + ");"

	vertexShaderSrc =
		"#version 120\n													 " \
		"uniform mat4 u_Projection;                                       " \
		"uniform mat4 u_Model;                                            " \
		"attribute vec3 a_Position;										" \
		"attribute vec2 a_TexCoord;                                       " \
		"attribute vec3 a_Normal;										" \
		"varying vec2 v_TexCoord;                                         " \
		"                                                                 " \
		"varying vec3 v_Normal;											  " \
		"varying vec3 v_FragPos;										  " \
		"																  " \
		"void main()                                                      " \
		"{                                                                " \
		"  gl_Position = u_Projection * u_Model * vec4(a_Position, 1.0);  " \
		"  v_TexCoord = a_TexCoord;                                       " \
		"  v_Normal = mat3(u_Model) * a_Normal;                           " \
		"  v_FragPos = vec3(u_Model * vec4(a_Position, 1.0));             " \
		"}                                                                " \
		"                                                                 ";

	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderId);
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(vertexShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile vertex shader");
	}

	fragmentShaderSrc =
		"uniform sampler2D u_Texture;                       " \
		"varying vec2 v_TexCoord;                           " \
		"varying vec3 v_Normal;                             " \
		"varying vec3 v_FragPos;                            " \
		"						                            " \
		"uniform vec3 u_ViewPos;						    " \
		"uniform vec3 u_View;						        " \
		"													" \
		"void main()                                        " \
		"{                                                  " \
		"  vec4 tex = texture2D(u_Texture, v_TexCoord);     " \
		"													" \
		"  vec3 lightPos = vec3(10, 10, 10);				" \
		"  vec3 diffuseColor = vec3(1, 1, 1);				" \
		"  													" \
		"  vec3 N = normalize(v_Normal);				    " \
		"  vec3 lightDir = normalize(lightPos - v_FragPos);	" \
		"  float diff = max(dot(N, lightDir), 0.0);			" \
		"  vec3 diffuse = diffuseColor * diff;				" \
		"													" \
		"  vec3 specularColor = vec3(1, 1, 1);				" \
		"  vec3 viewPos = vec3(0, 0, 0);					" \
		"  vec3 viewDir = normalize(viewPos - v_FragPos);	" \
		"  vec3 reflectDir = reflect(-lightDir, N);         " \
		"  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);" \
		"  vec3 specular = spec * specularColor;			" \
		"													" \
		"  vec3 lighting = diffuse + specular;				" \
		"  gl_FragColor = vec4(lighting, 1) * tex;		" \
		"}                                                  " \
		"                                                   ";

	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(fragmentShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile fragment shader");
	}

	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "a_Position");
	glBindAttribLocation(programId, 1, "a_TexCoord");
	glBindAttribLocation(programId, 2, "a_Normal");

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(programId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(programId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to link shader program");
	}

	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}

Shader::~Shader()
{
	//delete the program
}

void Shader::CreateVertexShader()
{
	vertexShaderSrc =
		"#version 120\n													 " \
		"uniform mat4 u_Projection;                                       " \
		"uniform mat4 u_Model;                                            " \
		"attribute vec3 a_Position;                                       " \
		"attribute vec2 a_TexCoord;                                       " \
		"attribute vec3 a_Normal;										" \
		"varying vec2 v_TexCoord;                                         " \
		"                                                                 " \
		"varying vec3 v_Normal;											  " \
		"varying vec3 v_FragPos;										  " \
		"																  " \
		"void main()                                                      " \
		"{                                                                " \
		"  gl_Position = u_Projection * u_Model * vec4(a_Position, 1.0);  " \
		"  v_TexCoord = a_TexCoord;                                       " \
		"  v_Normal = mat3(u_Model) * a_Normal;                           " \
		"  v_FragPos = vec3(u_Model * vec4(a_Position, 1.0));             " \
		"}                                                                " \
		"                                                                 ";

	vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vertexShaderSrc, NULL);
	glCompileShader(vertexShaderId);
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(vertexShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(vertexShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile vertex shader");
	}
}

void Shader::CreateFragmentShader()
{
	fragmentShaderSrc =
		"uniform sampler2D u_Texture;                       " \
		"varying vec2 v_TexCoord;                           " \
		"varying vec3 v_Normal;                             " \
		"varying vec3 v_FragPos;                            " \
		"						                            " \
		"uniform vec3 u_ViewPos;						    " \
		"uniform vec3 u_View;						        " \
		"													" \
		"void main()                                        " \
		"{                                                  " \
		"  vec4 tex = texture2D(u_Texture, v_TexCoord);     " \
		"													" \
		"  vec3 lightPos = vec3(10, 10, 10);				" \
		"  vec3 diffuseColor = vec3(1, 1, 1);				" \
		"  													" \
		"  vec3 N = normalize(v_Normal);				    " \
		"  vec3 lightDir = normalize(lightPos - v_FragPos);	" \
		"  float diff = max(dot(N, lightDir), 0.0);			" \
		"  vec3 diffuse = diffuseColor * diff;				" \
		"													" \
		"  vec3 specularColor = vec3(1, 1, 1);				" \
		"  vec3 viewPos = vec3(0, 0, 0);					" \
		"  vec3 viewDir = normalize(viewPos - v_FragPos);	" \
		"  vec3 reflectDir = reflect(-lightDir, N);         " \
		"  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);" \
		"  vec3 specular = spec * specularColor;			" \
		"													" \
		"  vec3 lighting = diffuse + specular;				" \
		"  gl_FragColor = vec4(lighting, 1) * tex;		" \
		"}                                                  " \
		"                                                   ";

	fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(fragmentShaderId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(fragmentShaderId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to compile fragment shader");
	}
}

void Shader::CreateProgramId()
{
	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glBindAttribLocation(programId, 0, "a_Position");
	glBindAttribLocation(programId, 1, "a_TexCoord");
	glBindAttribLocation(programId, 2, "a_Normal");

	glLinkProgram(programId);
	glGetProgramiv(programId, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint maxLength = 0;
		glGetShaderiv(programId, GL_INFO_LOG_LENGTH,
			&maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(programId, maxLength,
			&maxLength, &errorLog[0]);
		std::cout << &errorLog.at(0) << std::endl;
		throw std::runtime_error("Failed to link shader program");
	}

	glDetachShader(programId, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(programId, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}

void Shader::Clear(GLint &pLoc, GLint &mLoc, Window &w, float &angle)
{
	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glUseProgram(GetProgramId());

	glUniformMatrix4fv(pLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(
		glm::radians(45.0f), (float)w.GetWindowHeight() / (float)w.GetWindowHeight(), 0.1f, 100.0f)));

	glUniformMatrix4fv(mLoc, 1, GL_FALSE, glm::value_ptr(glm::rotate(
		glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -4.0f)), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f))));

	angle += 1.0f;
}

void Shader::Draw()
{
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
	glUseProgram(0);

	glDisable(GL_DEPTH_TEST);
}
