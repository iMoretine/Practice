# Specification – Unity Game AI Programming Project

## Project Description

The aim of this project is to create a game that will use the Unity game engine, where a complex example of artificial intelligence is clearly displayed to the player, when playing against a large number of enemies controlled by AI. In order to create a solution to this project, the game that I will create will involve artificial intelligence through the game learning the playstyle of a player in a short first person shooter game and adapting the enemies (which willalso be controlled by the AI) and stage according to the style of play that the player adopts, in order to increase the difficulty. The game will follow a simple format of trying to survive for as long as possible while defeating the most enemies and include multiple stages/levels. This project will be completed under the supervision of Ullrich Hustadt.
## Statement of Deliverables
Throughout the duration of this project, I intend to create a variety of documents, such as the specification document which details the future plans for the project, a design document that will display a variety of diagrams such as use case diagrams and initial designs for code and a dissertation document that will provide a detailed account of the conduct and the outcome of the project.
The final software that will be produced will be in the form of a .exe file with a folder that contains all of the necessary game data, which will allow the game to be run on a Windows PC [4]. The main requirement for the game produced as a result of this project is that there must be a form of artificial intelligence included in the final product. Requirements for the game that I intend to create to display this AI can be found as follows;

- The game will take the form of a first person shooter game, in which the player will have to survive against waves of enemies created and controlled by the AI of the system.
- The difficulty of the game must be challenging to the player, but not to the level at which the game becomes impossible or unfair.
- Skill levels will differ greatly from player to player, therefore it is important that the AI is able to identify the skill level of the current player. If the player struggles to defeat many enemies, the AI could possibly spawn less enemies to ensure that the player is not overwhelmed, while if the player defeats a large number of enemies, more enemies could be spawned.
- The AI monitoring the game must be fair; if there is any indication that any changes have been too severe for the player’s progress, then the changes must be gradually reversed until an appropriate difficulty increase is identified. For example, both players and enemies will have health points that can be depleted if they are hit by projectiles from the weapons. Then, if increasing the number of enemies contributed to an 80% loss of player health points, then the number of enemies spawning could be decreased again.
- Multiple stages must be included, which will be of different shapes in order to encourage different tactics.
- The stages that are included in the game will have objects that are designed to be used for cover.
- The player will have access to multiple weapons in order to allow the AI to gather more detailed information about the player preferences. Examples include;
  - A long range weapon that takes the longest amount of time to reload,
  - A short range weapon that causes a high amount of damage when close,
  - A short range weapon that allows the player to move faster, but the weapon is the weakest,
  - A weapon that shoots in arc; this could be used to draw enemies and players out of cover.
- Each weapon will be available to be switched to at any time.
- The AI will spawn enemies according to the weapons that the player favours or is most skilled at; for example, if the AI learns that the player favours the powerful short range weapon, more long range enemies will be spawned to counter this playstyle.
- The movement style of the player will also be examined by the AI; if the player favours hiding in a specific location such as a corner and defeating enemies through this strategy, the AI will have the ability to change the layout of the current stage to adapt to this, such as increasing the size of the stage to provide more locations for enemies to spawn around the player.
- Tactics are another aspect that will be examined by the AI; if the player favours an aggressive strategy for example, the enemies could group together to ensure that the player is unable to defeat enemies one by one in order to counter this strategy.

While developing the project, I will attempt various experiments to ensure that the AI learning capabilities are meeting the initial requirements. An experiment that I will undertake will involve playing the game using specific tactics, in order to obtain a response from the AI; this could involve playing the game using only the strong, short range weapon to identify if the AI will begin to spawn the enemies that counter this strategy – in this case, enemies using long range weapons.

Evaluating the software will require several third parties and myself. During the design stage, I will create a questionnaire that will be used for evaluation at the end of the implementation stage. The third parties will consist of friends and family, who will play the game and fill out a questionnaire after they have played the game. This evaluation will comply with the Computer Science Student Project Third Party Evaluation Procedure. 

## Conduct of the Project and Plan

### Preparation

Since I was assigned to this project back in May, I have already worked on some preparations for this project. During my year in industry, the language that I used the most throughout my various tasks was C#, which is used in the Unity game engine, in which this project will be built. Additionally, I also worked on some small side projects in Unity in my own time which I will refer back to, involving AI that changed location based on the location of the player. 

As much of the source code of the Unity game engine is open and many different templates are included [5], I will examine any existing code that is related to the artificial intelligence and movement procedures and identify how I may create code that meets the demands of the game that I am required to create. I will also ensure that I research in depth how AI can be applied in the Unity engine using the theory of machine learning [1].

Additionally, I will research a large amount of information regarding artificial intelligence and machine learning – I hope to specify the level of learning at which the AI will follow, during the design stage. However, during my preparations for the design, I will research the different types of learning that are available to artificial intelligence programs, such as learning by instruction and learning by observation and discovery [3].

### Design

During the design stage, I will create a document that will contain many different diagrams and designs that will indicate the direction for which the project will take, in which the designs have been created using a top-down design methodology. The following are expected to be included in the document;

- Anticipated Outcomes; describes what is expected of the project,
- Sketches; these will detail the design for the player, enemies, stages and the user interface,
- Storyboard; this may display examples of scenarios that may occur in the game,
- Uses Cases; the interaction that takes place between the user and software will be defined,
- Questionnaire; this will be used in the third party evaluation,
- Pseudocode; a design for the algorithm for the learning process will be included,
- Test Cases; the project will be tested against these test cases at the end of the project to ensure that there are no known bugs.
  ​
### Implementation
As this project requires the use of the Unity game engine, I will be developing the game for this project in Unity – however, due to the processing and graphical demands of Unity, I will mostly be working on this project using my PC at home, which is of a high end specification and will be able to run the software.

Other software applications that I will use include Visual Studio Community 2015 which is installed with Unity and allows for programs to be written in C#, as well as applications such as Blender, which will allow for the creation of some basic 3D assets that can be used within the game [2].

With regards to any demonstrations of the software that are required to take place; the final game product or any older versions will be able to run on either a Macbook Pro (running Windows 10) or a laptop designed for gaming.

In order to test the software, the test cases that were established during the design stage will be used to ensure that the software is without known bugs. Additionally, extra test cases may be added during the implementation stage should they be required. Testing will also be carried out using the black box and white box testing methods. 

## Risk Assessment

| Risk                                     | Likelihood | Impact                                   | Countermeasures                          |
| ---------------------------------------- | ---------- | ---------------------------------------- | ---------------------------------------- |
| Unexpected bugs, as the complexity of games can lead to many  difficult bugs to fix | High       | The amount of time that maybe spent on certain features may be reduced in order to fix any bugs that may appear. | While the presence of bugs is to be expected, I will allocate more time to work on features than the amount of time I expect it will take. This will ensure that if any difficult, unexpected bugs appear, that my plans should not be affected. |
| Lacking in skills with regards to the creation of assets | Medium     | Any assets made for the game may be lacking and may take longer than intended. | In order to avoid the risk of lacking these skills, I will attempt to learn how to use software applications such as Blender in advance of developing the project. I will also design any assets with simplicity in mind. |
| Difficulties with programming in the Unity game engine | Low        | Various aspects of the game may take longer to complete, such as programming the use of projectiles. | The Unity game engine has a large number of documents and tutorials available online that I will refer to, should I require any help.Additionally, I can look back at previous projects that I have worked on in the past for help. |

## Bibliography


[1] Ray Barrera, Aung Sithu Kyaw, Clifford Peters, Thet Naing Swe: Unity Game AI Programming (2nd Edition), Packt Publishing, 2015.
[2] Blender: About, https://www.blender.org/about/ Date Last Accessed: 19/10/2016 20:00
[3] R.S. Michalski, J.G. Carbonell, T.M. Mitchell: Machine Learning, An Artificial Intelligence Approach, Springer, 2013
[4] Unity: Publishing Builds, https://docs.unity3d.com/Manual/PublishingBuilds.html Date Last Accessed: 19/10/2016 20:00
[5] Unity: Standard Assets, https://docs.unity3d.com/Manual/HOWTO-InstallStandardAssets.html Date Last Accessed: 19/10/2016 20:00 




