#ifndef VIEW_GAME_VIEW_H_
#define VIEW_GAME_VIEW_H_

#include <QGraphicsView>

class GameView : public QGraphicsView {
 public:
  explicit GameView(QGraphicsScene* scene);
};

#endif  // VIEW_GAME_VIEW_H_
