from OCCT.AIS import AIS_InteractiveObject
from OCCT.Graphic3d import Graphic3d_Group
from OCCT.Prs3d import Prs3d_Arrow
from OCCT.gp import gp_Pnt, gp_Dir, gp_Ax2

try:
    from OCCT.Visualization.WxViewer import ShapeViewerWx as ShapeViewer

    use_wx = True
except ModuleNotFoundError:
    from OCCT.Visualization.QtViewer import ShapeViewerQt as ShapeViewer

    use_wx = False


class AIS_Arrow(AIS_InteractiveObject):
    def __init__(self, axis, tube_radius, axis_length,
                 cone_radius, cone_length, number_of_facetts=360):
        super().__init__()
        self.params = (axis, tube_radius, axis_length,
                       cone_radius, cone_length, int(number_of_facetts))
        self.SetInfiniteState(True)

    def Compute(self, prs_mgr, pres, mode):
        group = pres.CurrentGroup()
        handle = Prs3d_Arrow.DrawShaded_(*self.params)
        group.SetPrimitivesAspect(self.Attributes().ShadingAspect().Aspect())
        group.__class__ = Graphic3d_Group  # Hack?
        group.AddPrimitiveArray(handle)

    def ComputeSelection(self, pres, mode):
        pass


axis = gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0)).Axis()
ais_arrow = AIS_Arrow(axis, 0.5, 3, 1, 1)

v = ShapeViewer()
if use_wx:
    v.display_ais(ais_arrow)
else:
    v.view.display(ais_arrow)
v.start()
