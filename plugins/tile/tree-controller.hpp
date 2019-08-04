#ifndef WF_TILE_PLUGIN_TREE_CONTROLLER_HPP
#define WF_TILE_PLUGIN_TREE_CONTROLLER_HPP

#include "tree.hpp"
#include <config.hpp>

/* Contains functions which are related to manipulating the tiling tree */
namespace wf
{
class preview_indication_view_t;
namespace tile
{
/**
 * Represents the current mode in which the tile plugin is.
 */
class tile_controller_t
{
  public:
    /** The tile controller is destroyed when the action has come to and end,
     * for ex. when the mouse button is released */
    virtual ~tile_controller_t() = default;

    /** Called when the input is moved */
    virtual void input_motion(wf_point input) {}
};

/**
 * Represents the moving view action, i.e dragging a window to change its
 * position in the grid
 */
class move_view_controller_t : public tile_controller_t
{
  public:
    /**
     * Start the dragging action.
     *
     * @param root The root of the tiling tree which is currently being
     *             manipulated
     * @param Where the grab has started
     */
    move_view_controller_t(nonstd::observer_ptr<tree_node_t> root,
        wf_point grab);

    /** Called when the input is released */
    ~move_view_controller_t();

    void input_motion(wf_point input) override;

  protected:
    nonstd::observer_ptr<tree_node_t> root;
    nonstd::observer_ptr<view_node_t> grabbed_view;

    nonstd::observer_ptr<wf::preview_indication_view_t> preview;
    /**
     * Create preview if it doesn't exist
     *
     * @param now The position of the input now. Used only if the preview
     *            needs to be created.
     *
     * @param output The output on which to create the preview. Used only if
     *               the preview needs to be created.
     */
    void ensure_preview(wf_point now, wf::output_t *output);
};

}
}


#endif /* end of include guard: WF_TILE_PLUGIN_TREE_CONTROLLER_HPP */

