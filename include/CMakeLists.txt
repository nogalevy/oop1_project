target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR} )
target_sources (${CMAKE_PROJECT_NAME} PRIVATE "Board.h"
                                              "DynamicObject.h"
                                              "GameObject.h"
                                              "King.h"
                                              "Menu.h"
                                              "StaticObject.h"
                                              "utilities.h"
                                              "view_constants.h"
                                             )