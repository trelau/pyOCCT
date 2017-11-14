#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BRep_Builder.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pln.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepPrim_Builder.hxx>
#include <BRepPrim_Direction.hxx>
#include <gp_Ax2.hxx>
#include <BRepPrim_GWedge.hxx>
#include <BRepPrim_Wedge.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepPrim_OneAxis.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <BRepPrim_Revolution.hxx>
#include <BRepPrim_Cone.hxx>
#include <BRepPrim_Cylinder.hxx>
#include <BRepPrim_Sphere.hxx>
#include <BRepPrim_Torus.hxx>
#include <Geom_Surface.hxx>
#include <BRepPrim_FaceBuilder.hxx>

PYBIND11_MODULE(BRepPrim, mod) {

	// IMPORT
	py::module::import("OCCT.BRep");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Direction.hxx
	py::enum_<BRepPrim_Direction>(mod, "BRepPrim_Direction", "None")
		.value("BRepPrim_XMin", BRepPrim_Direction::BRepPrim_XMin)
		.value("BRepPrim_XMax", BRepPrim_Direction::BRepPrim_XMax)
		.value("BRepPrim_YMin", BRepPrim_Direction::BRepPrim_YMin)
		.value("BRepPrim_YMax", BRepPrim_Direction::BRepPrim_YMax)
		.value("BRepPrim_ZMin", BRepPrim_Direction::BRepPrim_ZMin)
		.value("BRepPrim_ZMax", BRepPrim_Direction::BRepPrim_ZMax)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Builder.hxx
	py::class_<BRepPrim_Builder, std::unique_ptr<BRepPrim_Builder, Deleter<BRepPrim_Builder>>> cls_BRepPrim_Builder(mod, "BRepPrim_Builder", "implements the abstract Builder with the BRep Builder");
	cls_BRepPrim_Builder.def(py::init<>());
	cls_BRepPrim_Builder.def(py::init<const BRep_Builder &>(), py::arg("B"));
	cls_BRepPrim_Builder.def("Builder", (const BRep_Builder & (BRepPrim_Builder::*)() const ) &BRepPrim_Builder::Builder, "None");
	cls_BRepPrim_Builder.def("MakeShell", (void (BRepPrim_Builder::*)(TopoDS_Shell &) const ) &BRepPrim_Builder::MakeShell, "Make a empty Shell.", py::arg("S"));
	cls_BRepPrim_Builder.def("MakeFace", (void (BRepPrim_Builder::*)(TopoDS_Face &, const gp_Pln &) const ) &BRepPrim_Builder::MakeFace, "Returns in <F> a Face built with the plane equation <P>. Used by all primitives.", py::arg("F"), py::arg("P"));
	cls_BRepPrim_Builder.def("MakeWire", (void (BRepPrim_Builder::*)(TopoDS_Wire &) const ) &BRepPrim_Builder::MakeWire, "Returns in <W> an empty Wire.", py::arg("W"));
	cls_BRepPrim_Builder.def("MakeDegeneratedEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &) const ) &BRepPrim_Builder::MakeDegeneratedEdge, "Returns in <E> a degenerated edge.", py::arg("E"));
	cls_BRepPrim_Builder.def("MakeEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const gp_Lin &) const ) &BRepPrim_Builder::MakeEdge, "Returns in <E> an Edge built with the line equation <L>.", py::arg("E"), py::arg("L"));
	cls_BRepPrim_Builder.def("MakeEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const gp_Circ &) const ) &BRepPrim_Builder::MakeEdge, "Returns in <E> an Edge built with the circle equation <C>.", py::arg("E"), py::arg("C"));
	cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Lin2d &) const ) &BRepPrim_Builder::SetPCurve, "Sets the line <L> to be the curve representing the edge <E> in the parametric space of the surface of <F>.", py::arg("E"), py::arg("F"), py::arg("L"));
	cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Lin2d &, const gp_Lin2d &) const ) &BRepPrim_Builder::SetPCurve, "Sets the lines <L1,L2> to be the curves representing the edge <E> in the parametric space of the closed surface of <F>.", py::arg("E"), py::arg("F"), py::arg("L1"), py::arg("L2"));
	cls_BRepPrim_Builder.def("SetPCurve", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Face &, const gp_Circ2d &) const ) &BRepPrim_Builder::SetPCurve, "Sets the circle <C> to be the curve representing the edge <E> in the parametric space of the surface of <F>.", py::arg("E"), py::arg("F"), py::arg("C"));
	cls_BRepPrim_Builder.def("MakeVertex", (void (BRepPrim_Builder::*)(TopoDS_Vertex &, const gp_Pnt &) const ) &BRepPrim_Builder::MakeVertex, "Returns in <V> a Vertex built with the point <P>.", py::arg("V"), py::arg("P"));
	cls_BRepPrim_Builder.def("ReverseFace", (void (BRepPrim_Builder::*)(TopoDS_Face &) const ) &BRepPrim_Builder::ReverseFace, "Reverses the Face <F>.", py::arg("F"));
	cls_BRepPrim_Builder.def("AddEdgeVertex", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Boolean) const ) &BRepPrim_Builder::AddEdgeVertex, "Adds the Vertex <V> in the Edge <E>. <P> is the parameter of the vertex on the edge. If direct is False the Vertex is reversed.", py::arg("E"), py::arg("V"), py::arg("P"), py::arg("direct"));
	cls_BRepPrim_Builder.def("AddEdgeVertex", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real) const ) &BRepPrim_Builder::AddEdgeVertex, "Adds the Vertex <V> in the Edge <E>. <P1,P2> are the parameters of the vertex on the closed edge.", py::arg("E"), py::arg("V"), py::arg("P1"), py::arg("P2"));
	cls_BRepPrim_Builder.def("SetParameters", (void (BRepPrim_Builder::*)(TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real) const ) &BRepPrim_Builder::SetParameters, "<P1,P2> are the parameters of the vertex on the edge. The edge is a closed curve.", py::arg("E"), py::arg("V"), py::arg("P1"), py::arg("P2"));
	cls_BRepPrim_Builder.def("AddWireEdge", (void (BRepPrim_Builder::*)(TopoDS_Wire &, const TopoDS_Edge &, const Standard_Boolean) const ) &BRepPrim_Builder::AddWireEdge, "Adds the Edge <E> in the Wire <W>, if direct is False the Edge is reversed.", py::arg("W"), py::arg("E"), py::arg("direct"));
	cls_BRepPrim_Builder.def("AddFaceWire", (void (BRepPrim_Builder::*)(TopoDS_Face &, const TopoDS_Wire &) const ) &BRepPrim_Builder::AddFaceWire, "Adds the Wire <W> in the Face <F>.", py::arg("F"), py::arg("W"));
	cls_BRepPrim_Builder.def("AddShellFace", (void (BRepPrim_Builder::*)(TopoDS_Shell &, const TopoDS_Face &) const ) &BRepPrim_Builder::AddShellFace, "Adds the Face <F> in the Shell <Sh>.", py::arg("Sh"), py::arg("F"));
	cls_BRepPrim_Builder.def("CompleteEdge", (void (BRepPrim_Builder::*)(TopoDS_Edge &) const ) &BRepPrim_Builder::CompleteEdge, "This is called once an edge is completed. It gives the opportunity to perform any post treatment.", py::arg("E"));
	cls_BRepPrim_Builder.def("CompleteWire", (void (BRepPrim_Builder::*)(TopoDS_Wire &) const ) &BRepPrim_Builder::CompleteWire, "This is called once a wire is completed. It gives the opportunity to perform any post treatment.", py::arg("W"));
	cls_BRepPrim_Builder.def("CompleteFace", (void (BRepPrim_Builder::*)(TopoDS_Face &) const ) &BRepPrim_Builder::CompleteFace, "This is called once a face is completed. It gives the opportunity to perform any post treatment.", py::arg("F"));
	cls_BRepPrim_Builder.def("CompleteShell", (void (BRepPrim_Builder::*)(TopoDS_Shell &) const ) &BRepPrim_Builder::CompleteShell, "This is called once a shell is completed. It gives the opportunity to perform any post treatment.", py::arg("S"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_GWedge.hxx
	py::class_<BRepPrim_GWedge, std::unique_ptr<BRepPrim_GWedge, Deleter<BRepPrim_GWedge>>> cls_BRepPrim_GWedge(mod, "BRepPrim_GWedge", "A wedge is defined by :");
	cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
	cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
	cls_BRepPrim_GWedge.def(py::init<const BRepPrim_Builder &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("Axes"), py::arg("xmin"), py::arg("ymin"), py::arg("zmin"), py::arg("z2min"), py::arg("x2min"), py::arg("xmax"), py::arg("ymax"), py::arg("zmax"), py::arg("z2max"), py::arg("x2max"));
	cls_BRepPrim_GWedge.def("Axes", (gp_Ax2 (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::Axes, "Returns the coordinates system from <me>.");
	cls_BRepPrim_GWedge.def("GetXMin", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetXMin, "Returns Xmin value from <me>.");
	cls_BRepPrim_GWedge.def("GetYMin", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetYMin, "Returns YMin value from <me>.");
	cls_BRepPrim_GWedge.def("GetZMin", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetZMin, "Returns ZMin value from <me>.");
	cls_BRepPrim_GWedge.def("GetZ2Min", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetZ2Min, "Returns Z2Min value from <me>.");
	cls_BRepPrim_GWedge.def("GetX2Min", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetX2Min, "Returns X2Min value from <me>.");
	cls_BRepPrim_GWedge.def("GetXMax", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetXMax, "Returns XMax value from <me>.");
	cls_BRepPrim_GWedge.def("GetYMax", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetYMax, "Returns YMax value from <me>.");
	cls_BRepPrim_GWedge.def("GetZMax", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetZMax, "Returns ZMax value from <me>.");
	cls_BRepPrim_GWedge.def("GetZ2Max", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetZ2Max, "Returns Z2Max value from <me>.");
	cls_BRepPrim_GWedge.def("GetX2Max", (Standard_Real (BRepPrim_GWedge::*)() const ) &BRepPrim_GWedge::GetX2Max, "Returns X2Max value from <me>.");
	cls_BRepPrim_GWedge.def("Open", (void (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Open, "Opens <me> in <d1> direction. A face and its edges or vertices are said nonexistant.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("Close", (void (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Close, "Closes <me> in <d1> direction. A face and its edges or vertices are said existant.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("IsInfinite", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const ) &BRepPrim_GWedge::IsInfinite, "Returns True if <me> is open in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("Shell", (const TopoDS_Shell & (BRepPrim_GWedge::*)()) &BRepPrim_GWedge::Shell, "Returns the Shell containing the Faces of <me>.");
	cls_BRepPrim_GWedge.def("HasFace", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const ) &BRepPrim_GWedge::HasFace, "Returns True if <me> has a Face in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("Face", (const TopoDS_Face & (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Face, "Returns the Face of <me> located in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("Plane", (gp_Pln (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Plane, "Returns the plane of the Face of <me> located in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("HasWire", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction) const ) &BRepPrim_GWedge::HasWire, "Returns True if <me> has a Wire in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("Wire", (const TopoDS_Wire & (BRepPrim_GWedge::*)(const BRepPrim_Direction)) &BRepPrim_GWedge::Wire, "Returns the Wire of <me> located in <d1> direction.", py::arg("d1"));
	cls_BRepPrim_GWedge.def("HasEdge", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction) const ) &BRepPrim_GWedge::HasEdge, "Returns True if <me> has an Edge in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
	cls_BRepPrim_GWedge.def("Edge", (const TopoDS_Edge & (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Edge, "Returns the Edge of <me> located in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
	cls_BRepPrim_GWedge.def("Line", (gp_Lin (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Line, "Returns the line of the Edge of <me> located in <d1><d2> direction.", py::arg("d1"), py::arg("d2"));
	cls_BRepPrim_GWedge.def("HasVertex", (Standard_Boolean (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction) const ) &BRepPrim_GWedge::HasVertex, "Returns True if <me> has a Vertex in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));
	cls_BRepPrim_GWedge.def("Vertex", (const TopoDS_Vertex & (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Vertex, "Returns the Vertex of <me> located in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));
	cls_BRepPrim_GWedge.def("Point", (gp_Pnt (BRepPrim_GWedge::*)(const BRepPrim_Direction, const BRepPrim_Direction, const BRepPrim_Direction)) &BRepPrim_GWedge::Point, "Returns the point of the Vertex of <me> located in <d1><d2><d3> direction.", py::arg("d1"), py::arg("d2"), py::arg("d3"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Wedge.hxx
	py::class_<BRepPrim_Wedge, std::unique_ptr<BRepPrim_Wedge, Deleter<BRepPrim_Wedge>>, BRepPrim_GWedge> cls_BRepPrim_Wedge(mod, "BRepPrim_Wedge", "Provides constructors without Builders.");
	cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"));
	cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
	cls_BRepPrim_Wedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("xmin"), py::arg("ymin"), py::arg("zmin"), py::arg("z2min"), py::arg("x2min"), py::arg("xmax"), py::arg("ymax"), py::arg("zmax"), py::arg("z2max"), py::arg("x2max"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_OneAxis.hxx
	py::class_<BRepPrim_OneAxis, std::unique_ptr<BRepPrim_OneAxis, Deleter<BRepPrim_OneAxis>>> cls_BRepPrim_OneAxis(mod, "BRepPrim_OneAxis", "Algorithm to build primitives with one axis of revolution.");
	cls_BRepPrim_OneAxis.def("SetMeridianOffset", [](BRepPrim_OneAxis &self) -> void { return self.SetMeridianOffset(); });
	cls_BRepPrim_OneAxis.def("SetMeridianOffset", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::SetMeridianOffset, "The MeridianOffset is added to the parameters on the meridian curve and to the V values of the pcurves. This is used for the sphere for example, to give a range on the meridian edge which is not VMin, VMax.", py::arg("MeridianOffset"));
	cls_BRepPrim_OneAxis.def("Axes", (const gp_Ax2 & (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::Axes, "Returns the Ax2 from <me>.");
	cls_BRepPrim_OneAxis.def("Axes", (void (BRepPrim_OneAxis::*)(const gp_Ax2 &)) &BRepPrim_OneAxis::Axes, "None", py::arg("A"));
	cls_BRepPrim_OneAxis.def("Angle", (Standard_Real (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::Angle, "None");
	cls_BRepPrim_OneAxis.def("Angle", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::Angle, "None", py::arg("A"));
	cls_BRepPrim_OneAxis.def("VMin", (Standard_Real (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::VMin, "None");
	cls_BRepPrim_OneAxis.def("VMin", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::VMin, "None", py::arg("V"));
	cls_BRepPrim_OneAxis.def("VMax", (Standard_Real (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::VMax, "None");
	cls_BRepPrim_OneAxis.def("VMax", (void (BRepPrim_OneAxis::*)(const Standard_Real)) &BRepPrim_OneAxis::VMax, "None", py::arg("V"));
	cls_BRepPrim_OneAxis.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::MakeEmptyLateralFace, "Returns a face with no edges. The surface is the lateral surface with normals pointing outward. The U parameter is the angle with the origin on the X axis. The V parameter is the parameter of the meridian.");
	cls_BRepPrim_OneAxis.def("MakeEmptyMeridianEdge", (TopoDS_Edge (BRepPrim_OneAxis::*)(const Standard_Real) const ) &BRepPrim_OneAxis::MakeEmptyMeridianEdge, "Returns an edge with a 3D curve made from the meridian in the XZ plane rotated by <Ang> around the Z-axis. Ang may be 0 or myAngle.", py::arg("Ang"));
	cls_BRepPrim_OneAxis.def("SetMeridianPCurve", (void (BRepPrim_OneAxis::*)(TopoDS_Edge &, const TopoDS_Face &) const ) &BRepPrim_OneAxis::SetMeridianPCurve, "Sets the parametric curve of the edge <E> in the face <F> to be the 2d representation of the meridian.", py::arg("E"), py::arg("F"));
	cls_BRepPrim_OneAxis.def("MeridianValue", (gp_Pnt2d (BRepPrim_OneAxis::*)(const Standard_Real) const ) &BRepPrim_OneAxis::MeridianValue, "Returns the meridian point at parameter <V> in the plane XZ.", py::arg("V"));
	cls_BRepPrim_OneAxis.def("MeridianOnAxis", (Standard_Boolean (BRepPrim_OneAxis::*)(const Standard_Real) const ) &BRepPrim_OneAxis::MeridianOnAxis, "Returns True if the point of parameter <V> on the meridian is on the Axis. Default implementation is Abs(MeridianValue(V).X()) < Precision::Confusion()", py::arg("V"));
	cls_BRepPrim_OneAxis.def("MeridianClosed", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::MeridianClosed, "Returns True if the meridian is closed. Default implementation is MeridianValue(VMin).IsEqual(MeridianValue(VMax), Precision::Confusion())");
	cls_BRepPrim_OneAxis.def("VMaxInfinite", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::VMaxInfinite, "Returns True if VMax is infinite. Default Precision::IsPositiveInfinite(VMax);");
	cls_BRepPrim_OneAxis.def("VMinInfinite", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::VMinInfinite, "Returns True if VMin is infinite. Default Precision::IsNegativeInfinite(VMax);");
	cls_BRepPrim_OneAxis.def("HasTop", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::HasTop, "Returns True if there is a top face.");
	cls_BRepPrim_OneAxis.def("HasBottom", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::HasBottom, "Returns True if there is a bottom face.");
	cls_BRepPrim_OneAxis.def("HasSides", (Standard_Boolean (BRepPrim_OneAxis::*)() const ) &BRepPrim_OneAxis::HasSides, "Returns True if there are Start and End faces.");
	cls_BRepPrim_OneAxis.def("Shell", (const TopoDS_Shell & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::Shell, "Returns the Shell containing all the Faces of the primitive.");
	cls_BRepPrim_OneAxis.def("LateralFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralFace, "Returns the lateral Face. It is oriented toward the outside of the primitive.");
	cls_BRepPrim_OneAxis.def("TopFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopFace, "Returns the top planar Face. It is Oriented toward the +Z axis (outside).");
	cls_BRepPrim_OneAxis.def("BottomFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomFace, "Returns the Bottom planar Face. It is Oriented toward the -Z axis (outside).");
	cls_BRepPrim_OneAxis.def("StartFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartFace, "Returns the Face starting the slice, it is oriented toward the exterior of the primitive.");
	cls_BRepPrim_OneAxis.def("EndFace", (const TopoDS_Face & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndFace, "Returns the Face ending the slice, it is oriented toward the exterior of the primitive.");
	cls_BRepPrim_OneAxis.def("LateralWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralWire, "Returns the wire in the lateral face.");
	cls_BRepPrim_OneAxis.def("LateralStartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralStartWire, "Returns the wire in the lateral face with the start edge.");
	cls_BRepPrim_OneAxis.def("LateralEndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::LateralEndWire, "Returns the wire with in lateral face with the end edge.");
	cls_BRepPrim_OneAxis.def("TopWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopWire, "Returns the wire in the top face.");
	cls_BRepPrim_OneAxis.def("BottomWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomWire, "Returns the wire in the bottom face.");
	cls_BRepPrim_OneAxis.def("StartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartWire, "Returns the wire in the start face.");
	cls_BRepPrim_OneAxis.def("AxisStartWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisStartWire, "Returns the wire in the start face with the AxisEdge.");
	cls_BRepPrim_OneAxis.def("EndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndWire, "Returns the Wire in the end face.");
	cls_BRepPrim_OneAxis.def("AxisEndWire", (const TopoDS_Wire & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisEndWire, "Returns the Wire in the end face with the AxisEdge.");
	cls_BRepPrim_OneAxis.def("AxisEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisEdge, "Returns the Edge built along the Axis and oriented on +Z of the Axis.");
	cls_BRepPrim_OneAxis.def("StartEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartEdge, "Returns the Edge at angle 0.");
	cls_BRepPrim_OneAxis.def("EndEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndEdge, "Returns the Edge at angle Angle. If !HasSides() the StartEdge and the EndEdge are the same edge.");
	cls_BRepPrim_OneAxis.def("StartTopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartTopEdge, "Returns the linear Edge between start Face and top Face.");
	cls_BRepPrim_OneAxis.def("StartBottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::StartBottomEdge, "Returns the linear Edge between start Face and bottom Face.");
	cls_BRepPrim_OneAxis.def("EndTopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndTopEdge, "Returns the linear Edge between end Face and top Face.");
	cls_BRepPrim_OneAxis.def("EndBottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::EndBottomEdge, "Returns the linear Edge between end Face and bottom Face.");
	cls_BRepPrim_OneAxis.def("TopEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopEdge, "Returns the edge at VMax. If MeridianClosed() the TopEdge and the BottomEdge are the same edge.");
	cls_BRepPrim_OneAxis.def("BottomEdge", (const TopoDS_Edge & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomEdge, "Returns the edge at VMin. If MeridianClosed() the TopEdge and the BottomEdge are the same edge.");
	cls_BRepPrim_OneAxis.def("AxisTopVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisTopVertex, "Returns the Vertex at the Top altitude on the axis.");
	cls_BRepPrim_OneAxis.def("AxisBottomVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::AxisBottomVertex, "Returns the Vertex at the Bottom altitude on the axis.");
	cls_BRepPrim_OneAxis.def("TopStartVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopStartVertex, "Returns the vertex (0,VMax)");
	cls_BRepPrim_OneAxis.def("TopEndVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::TopEndVertex, "Returns the vertex (angle,VMax)");
	cls_BRepPrim_OneAxis.def("BottomStartVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomStartVertex, "Returns the vertex (0,VMin)");
	cls_BRepPrim_OneAxis.def("BottomEndVertex", (const TopoDS_Vertex & (BRepPrim_OneAxis::*)()) &BRepPrim_OneAxis::BottomEndVertex, "Returns the vertex (angle,VMax)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Revolution.hxx
	py::class_<BRepPrim_Revolution, std::unique_ptr<BRepPrim_Revolution, Deleter<BRepPrim_Revolution>>, BRepPrim_OneAxis> cls_BRepPrim_Revolution(mod, "BRepPrim_Revolution", "Implement the OneAxis algoritm for a revolution surface.");
	cls_BRepPrim_Revolution.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &>(), py::arg("A"), py::arg("VMin"), py::arg("VMax"), py::arg("M"), py::arg("PM"));
	cls_BRepPrim_Revolution.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Revolution::*)() const ) &BRepPrim_Revolution::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");
	cls_BRepPrim_Revolution.def("MakeEmptyMeridianEdge", (TopoDS_Edge (BRepPrim_Revolution::*)(const Standard_Real) const ) &BRepPrim_Revolution::MakeEmptyMeridianEdge, "Returns an edge with a 3D curve made from the meridian in the XZ plane rotated by <Ang> around the Z-axis. Ang may be 0 or myAngle.", py::arg("Ang"));
	cls_BRepPrim_Revolution.def("MeridianValue", (gp_Pnt2d (BRepPrim_Revolution::*)(const Standard_Real) const ) &BRepPrim_Revolution::MeridianValue, "Returns the meridian point at parameter <V> in the plane XZ.", py::arg("V"));
	cls_BRepPrim_Revolution.def("SetMeridianPCurve", (void (BRepPrim_Revolution::*)(TopoDS_Edge &, const TopoDS_Face &) const ) &BRepPrim_Revolution::SetMeridianPCurve, "Sets the parametric urve of the edge <E> in the face <F> to be the 2d representation of the meridian.", py::arg("E"), py::arg("F"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Cone.hxx
	py::class_<BRepPrim_Cone, std::unique_ptr<BRepPrim_Cone, Deleter<BRepPrim_Cone>>, BRepPrim_Revolution> cls_BRepPrim_Cone(mod, "BRepPrim_Cone", "Implement the cone primitive.");
	cls_BRepPrim_Cone.def(py::init<const Standard_Real, const gp_Ax2 &, const Standard_Real>(), py::arg("Angle"), py::arg("Position"), py::arg("Height"));
	cls_BRepPrim_Cone.def(py::init<const Standard_Real, const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Angle"), py::arg("Position"), py::arg("Height"), py::arg("Radius"));
	cls_BRepPrim_Cone.def(py::init<const Standard_Real>(), py::arg("Angle"));
	cls_BRepPrim_Cone.def(py::init<const Standard_Real, const gp_Pnt &>(), py::arg("Angle"), py::arg("Apex"));
	cls_BRepPrim_Cone.def(py::init<const Standard_Real, const gp_Ax2 &>(), py::arg("Angle"), py::arg("Axes"));
	cls_BRepPrim_Cone.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("H"));
	cls_BRepPrim_Cone.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R1"), py::arg("R2"), py::arg("H"));
	cls_BRepPrim_Cone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("H"));
	cls_BRepPrim_Cone.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Cone::*)() const ) &BRepPrim_Cone::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Cylinder.hxx
	py::class_<BRepPrim_Cylinder, std::unique_ptr<BRepPrim_Cylinder, Deleter<BRepPrim_Cylinder>>, BRepPrim_Revolution> cls_BRepPrim_Cylinder(mod, "BRepPrim_Cylinder", "Cylinder primitive.");
	cls_BRepPrim_Cylinder.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Position"), py::arg("Radius"), py::arg("Height"));
	cls_BRepPrim_Cylinder.def(py::init<const Standard_Real>(), py::arg("Radius"));
	cls_BRepPrim_Cylinder.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("Radius"));
	cls_BRepPrim_Cylinder.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("Axes"), py::arg("Radius"));
	cls_BRepPrim_Cylinder.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("H"));
	cls_BRepPrim_Cylinder.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("H"));
	cls_BRepPrim_Cylinder.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Cylinder::*)() const ) &BRepPrim_Cylinder::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Sphere.hxx
	py::class_<BRepPrim_Sphere, std::unique_ptr<BRepPrim_Sphere, Deleter<BRepPrim_Sphere>>, BRepPrim_Revolution> cls_BRepPrim_Sphere(mod, "BRepPrim_Sphere", "Implements the sphere primitive");
	cls_BRepPrim_Sphere.def(py::init<const Standard_Real>(), py::arg("Radius"));
	cls_BRepPrim_Sphere.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("Radius"));
	cls_BRepPrim_Sphere.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("Axes"), py::arg("Radius"));
	cls_BRepPrim_Sphere.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Sphere::*)() const ) &BRepPrim_Sphere::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_Torus.hxx
	py::class_<BRepPrim_Torus, std::unique_ptr<BRepPrim_Torus, Deleter<BRepPrim_Torus>>, BRepPrim_Revolution> cls_BRepPrim_Torus(mod, "BRepPrim_Torus", "Implements the torus primitive");
	cls_BRepPrim_Torus.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Position"), py::arg("Major"), py::arg("Minor"));
	cls_BRepPrim_Torus.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Major"), py::arg("Minor"));
	cls_BRepPrim_Torus.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("Major"), py::arg("Minor"));
	cls_BRepPrim_Torus.def("MakeEmptyLateralFace", (TopoDS_Face (BRepPrim_Torus::*)() const ) &BRepPrim_Torus::MakeEmptyLateralFace, "The surface normal should be directed towards the outside.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepPrim_FaceBuilder.hxx
	py::class_<BRepPrim_FaceBuilder, std::unique_ptr<BRepPrim_FaceBuilder, Deleter<BRepPrim_FaceBuilder>>> cls_BRepPrim_FaceBuilder(mod, "BRepPrim_FaceBuilder", "The FaceBuilder is an algorithm to build a BRep Face from a Geom Surface.");
	cls_BRepPrim_FaceBuilder.def(py::init<>());
	cls_BRepPrim_FaceBuilder.def(py::init<const BRep_Builder &, const opencascade::handle<Geom_Surface> &>(), py::arg("B"), py::arg("S"));
	cls_BRepPrim_FaceBuilder.def(py::init<const BRep_Builder &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("B"), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepPrim_FaceBuilder.def("Init", (void (BRepPrim_FaceBuilder::*)(const BRep_Builder &, const opencascade::handle<Geom_Surface> &)) &BRepPrim_FaceBuilder::Init, "None", py::arg("B"), py::arg("S"));
	cls_BRepPrim_FaceBuilder.def("Init", (void (BRepPrim_FaceBuilder::*)(const BRep_Builder &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepPrim_FaceBuilder::Init, "None", py::arg("B"), py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
	cls_BRepPrim_FaceBuilder.def("Face", (const TopoDS_Face & (BRepPrim_FaceBuilder::*)() const ) &BRepPrim_FaceBuilder::Face, "None");
	cls_BRepPrim_FaceBuilder.def("Edge", (const TopoDS_Edge & (BRepPrim_FaceBuilder::*)(const Standard_Integer) const ) &BRepPrim_FaceBuilder::Edge, "Returns the edge of index <I> 1 - Edge VMin 2 - Edge UMax 3 - Edge VMax 4 - Edge UMin", py::arg("I"));
	cls_BRepPrim_FaceBuilder.def("Vertex", (const TopoDS_Vertex & (BRepPrim_FaceBuilder::*)(const Standard_Integer) const ) &BRepPrim_FaceBuilder::Vertex, "Returns the vertex of index <I> 1 - Vertex UMin,VMin 2 - Vertex UMax,VMin 3 - Vertex UMax,VMax 4 - Vertex UMin,VMax", py::arg("I"));


}
