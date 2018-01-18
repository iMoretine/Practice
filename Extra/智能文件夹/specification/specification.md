# Specification - Student Information Searcher Programming Project

## Project Description

本项目的目的是编写一个学生信息搜索软件，该软件可以通过输入学生的ID来从pdf, word和excel等文档中提取与学生ID关联的信息。我选用C++作为编程语言[1]，Qt库作为工具库[2]， Qt Creator作为开发环境[3]，这样既可以创建美观的GUI程序，并能通过Qt库获得对pdf, word和excel等文档的支持。程序将以一个简洁的界面展示出来，程序界面将包含一个目录浏览框，一个搜索框和一个搜索结果框。用户在目录浏览框中选定目录，在搜索框中输入学生ID，程序将会在该目录下递归查询所有文件和子目录中的文件，并在文档文件中搜索与学生ID关联的信息，最后将搜索结果显示在搜索结果框中。其中，搜索结果将以多行展示，每行表示一个搜索结果，其中每行都包含文件名，文件所在目录，文件中学生ID的上下文摘要以及学生ID在文件中出现的位置。

## Statement of Deliverables

Throughout the duration of this project, I intend to create a variety of documents, such as the specification document which details the future plans for the project, a design document that will display a variety of diagrams such as use case diagrams and initial designs for code and a dissertation document that will provide a detailed account of the conduct and the outcome of the project.（这段与demo相同，可以直接使用）

最终软件将以一个exe文件交付，这个软件可以在Windows PC上运行。该软件的具体需求如下：

- 软件将能直接在Windows上运行，用户输入学生ID后将能搜索出所有相关的文档文件，并能清晰的展示出学生ID在文件中出现的位置。

- 程序界面的左侧栏是一个目录浏览框，类似于Windows目录的界面，用户将会非常熟练的调整并浏览当前目录。

- 程序界面的右侧是搜索结果框，其顶部是搜索框，它包含一个关键字输入栏和一个“Search”按钮。

- 搜索结果框将由上至下，每行展示一个搜索结果，即一个文件，同时在每行中，文件名后会显示文件所在目录，根据学生ID在文件中搜索到的上下文摘要，以及学生ID在文件中出现的位置。

- 对文件内容的搜索将支持txt, pdf, word和excel等常用文档文件。

- 搜索算法如下：

  - 使用深度优先搜索遍历每一个文件和目录

  - 在每个目录和文件名称中搜索学生ID（不只是文档文件），对于文档文件，不仅搜索文件名，还会搜索文件内容。

- 考虑到对于目录过多或过深，搜索时间可能过长的情况，搜索结果将每隔一定时间更新显示在搜索结果展示框内，而不是在完成所有搜索后一并展示。

在开发该项目的过程中，我将反复调试，以确保搜索结果和搜索体验达到以上需求。我会反复使用并修改程序，以使程序获得做好的性能。

软件评估将需要第三方和我自己来完成。在设计阶段，我会创建一个调查表，用于在实现阶段结束时进行评估。第三方将由我的朋友和家人组成，他们将使用程序，并在之后填写调查表。此评价方法符合 Computer Science Student Project Third Party Evaluation Procedure。

（上面一段和原文基本一致：Evaluating the software will require several third parties and myself. During the design stage, I will create a questionnaire that will be used for evaluation at the end of the implementation stage. The third parties will consist of friends and family, who will play the game and fill out a questionnaire after they have played the game. This evaluation will comply with the Computer Science Student Project Third Party Evaluation Procedure. ）

## Conduct of the Project and Plan

### Preparation

目前我已经为此项目做了一些准备工作，我已经尝试了解并掌握了C++的基本语法和编写技能[4]，一个合格的C++程序需要不少工程化的编程方式，我将使用面向对象等方法来编写该程序[5]。

同时，我也基本熟悉了Qt Creator作为开发环境，我已经尝试使用它构建了一些能够在Windows PC上运行的小程序。

Qt库将在本项目中提供程序界面和读写txt文件的基本操作，对于pdf, word和excel等文档文件的读写操作，我们需要ActiveQt来提供支持[6]，ActiveQt提供对微软ActiveX控件的支持，使得开发者可以在Qt中使用ActiveX控件。目前ActiveQt已经默认包含在Windows版的Qt库中，无需额外装载。

### Design
在设计阶段，我将创建一个设计文档，其中包含许多不同的图表，它们会给出项目开发的目标和方向。我使用自顶向下的设计方法来设计项目。详细内容将包括在以下文件中；
- 预期产出；描述该项目期望达到的目标，
- 草图；详细说明用户界面，程序流程和算法，
- 使用用例；定义一系列用户使用软件的操作，
- 问卷；这将用于第三方软件评估，
- 伪代码；用于快速描述程序流程和算法，
- 测试用例；项目将在项目结束时对这些测试用例进行测试，以确保没有已知的bug。


### Implementation

我将全程在Windows上使用Qt Creator和Qt库来开发程序，其中C++作为开发语言。

考虑到若ActiveQt对文档文件的支持不足的可能性，我会引入一些第三方的C++开源库用于读写文档文件，同时也会遵守对应的开源协议。

关于软件的展示，最终软件将可以运行在Windows 10电脑上。

关于软件的测试，在设计阶段建构建的测试用例将尽可能覆盖所有使用用例，来确保软件没有已知错误。此外，在实现阶段，还可以根据情况添加额外的测试用例。测试将使用黑盒和白盒测试的方法。

## Risk Assessment

| Risk                                     | Likelihood | Impact                                   | Countermeasures                          |
| ---------------------------------------- | ---------- | ---------------------------------------- | ---------------------------------------- |
| Qt库对文档文件的支持不足，因为word和excel的内容格式复杂，可能没有足够好的基本读写操作函数来支持文档文件 | High       | 可能会花费大量时间在支持文档文件的基本操作上，导致其他功能延后实现。       | 实现文档文件内容搜索的难度是可以预计的，我会花费比预期更多的时间来处理此问题。所以当出现任何难以预料的问题时，我的计划就不会受到影响。 |
| 缺乏足够的C++技能来编写软件                          | Medium     | C++是最复杂的语言之一，用其实现任何特性都可能比预期要长。           | 为了避免缺乏C++技能带来的风险，我会提前学习如何在开发项目之前使用C++开发简单的软件应用程序。 |
| 使用Qt开发环境的困难性                             | Low        | 即使Qt是优秀的C++工具库，但其依然存在着一些内部问题和使用难度。软件可能会在各个方面花费更多时间来完成。 | 当我遇到问题时，Qt有大量的文档和教程可参考。另外，我还会回顾一下我以前所做过的一些项目。 |

## Bibliography

[1] C++, Reference, http://www.cplusplus.com/reference/ Date Last Accessed: 18/10/2017 20:00
[2] Qt, Qt Documentation, http://doc.qt.io/qt-5/overviews-main.html Date Last Accessed: 18/10/2017 20:00
[3] Qt Creator, IDE Overview, http://doc.qt.io/qtcreator/creator-overview.html Date Last Accessed: 18/10/2017 20:00
[4] Stanley B. Lippman, Josee Lajoie, Barbara E. Moo: C++ Primer (5E), Pearson Education, 2013
[5] Scott Meyers: Effective C++: 55 Specific Ways to Improve Your Programs and Designs, 3rd Edition, Pearson Education, 2005
[6] Active Qt, Active Qt Documentation, http://doc.qt.io/qt-5/activeqt-index.html Date Last Accessed: 18/10/2017 20:00