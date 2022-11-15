#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager::SceneManager()
{

}
//Adds (Agregation) a Scene to the scene map
void SceneManager::AddScene(std::string name, Scene* s)
{
	scenes.emplace(name, s);
}

SceneManager* SceneManager::GetInstance() //Esto al parecer es un Singleton
{
	//Existe una instancia de esto? Si no existe, construyela
	if (instance == nullptr)
		instance = new SceneManager();
	return instance;
}

//Looks into the scene map for a scene with  a name
//Returns nullptr if not found
Scene* SceneManager::GetScene(std::string name)
{
	auto scene = scenes.find(name);

	bool sceneFound = scene != scenes.end();

	return sceneFound ? scenes[name] : nullptr;
}

//Returns a pointer to the current Scene
Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}

void SceneManager::SetScene(std::string name)
{
	auto scene = scenes.find(name);

	bool sceneFound = scene != scenes.end();
	assert(sceneFound); //Stop the code to warn the dev
	if (sceneFound)
	{
		if(currentScene != nullptr)
			currentScene->OnExit();
		currentScene = scene->second;
		currentScene->OnEnter();
	}
}