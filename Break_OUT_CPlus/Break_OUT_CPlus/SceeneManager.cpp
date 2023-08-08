#include"SceneManager.h"

AbstractScene* SceneManager::Update()
{
	AbstractScene* now_Scene = mScene->Update();
	if (now_Scene != mScene) 
	{
		delete mScene;
		mScene = now_Scene;
	}

	return now_Scene;
}
void SceneManager::Draw()const
{
	mScene->Draw();
}