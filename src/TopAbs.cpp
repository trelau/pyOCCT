#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs.hxx>

PYBIND11_MODULE(TopAbs, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopAbs_Orientation.hxx
	py::enum_<TopAbs_Orientation>(mod, "TopAbs_Orientation", "Identifies the orientation of a topological shape. Orientation can represent a relation between two entities, or it can apply to a shape in its own right. When used to describe a relation between two shapes, orientation allows you to use the underlying entity in either direction. For example on a curve which is oriented FORWARD (say from left to right) you can have both a FORWARD and a REVERSED edge. The FORWARD edge will be oriented from left to right, and the REVERSED edge from right to left. In this way, you share the underlying entity. In other words, two faces of a cube can share an edge, and can also be used to build compound shapes. For each case in which an element is used as the boundary of a geometric domain of a higher dimension, this element defines two local regions of which one is arbitrarily considered as the default region. A change in orientation implies a switch of default region. This allows you to apply changes of orientation to the shape as a whole.")
		.value("TopAbs_FORWARD", TopAbs_Orientation::TopAbs_FORWARD)
		.value("TopAbs_REVERSED", TopAbs_Orientation::TopAbs_REVERSED)
		.value("TopAbs_INTERNAL", TopAbs_Orientation::TopAbs_INTERNAL)
		.value("TopAbs_EXTERNAL", TopAbs_Orientation::TopAbs_EXTERNAL)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopAbs_State.hxx
	py::enum_<TopAbs_State>(mod, "TopAbs_State", "Identifies the position of a vertex or a set of vertices relative to a region of a shape. The figure shown above illustrates the states of vertices found in various parts of the edge relative to the face which it intersects.")
		.value("TopAbs_IN", TopAbs_State::TopAbs_IN)
		.value("TopAbs_OUT", TopAbs_State::TopAbs_OUT)
		.value("TopAbs_ON", TopAbs_State::TopAbs_ON)
		.value("TopAbs_UNKNOWN", TopAbs_State::TopAbs_UNKNOWN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopAbs_ShapeEnum.hxx
	py::enum_<TopAbs_ShapeEnum>(mod, "TopAbs_ShapeEnum", "Identifies various topological shapes. This enumeration allows you to use dynamic typing of shapes. The values are listed in order of complexity, from the most complex to the most simple i.e. COMPOUND > COMPSOLID > SOLID > .... > VERTEX > SHAPE. Any shape can contain simpler shapes in its definition. Abstract topological data structure describes a basic entity, the shape (present in this enumeration as the SHAPE value), which can be divided into the following component topologies: - COMPOUND: A group of any of the shapes below. - COMPSOLID: A set of solids connected by their faces. This expands the notions of WIRE and SHELL to solids. - SOLID: A part of 3D space bounded by shells. - SHELL: A set of faces connected by some of the edges of their wire boundaries. A shell can be open or closed. - FACE: Part of a plane (in 2D geometry) or a surface (in 3D geometry) bounded by a closed wire. Its geometry is constrained (trimmed) by contours. - WIRE: A sequence of edges connected by their vertices. It can be open or closed depending on whether the edges are linked or not. - EDGE: A single dimensional shape corresponding to a curve, and bound by a vertex at each extremity. - VERTEX: A zero-dimensional shape corresponding to a point in geometry.")
		.value("TopAbs_COMPOUND", TopAbs_ShapeEnum::TopAbs_COMPOUND)
		.value("TopAbs_COMPSOLID", TopAbs_ShapeEnum::TopAbs_COMPSOLID)
		.value("TopAbs_SOLID", TopAbs_ShapeEnum::TopAbs_SOLID)
		.value("TopAbs_SHELL", TopAbs_ShapeEnum::TopAbs_SHELL)
		.value("TopAbs_FACE", TopAbs_ShapeEnum::TopAbs_FACE)
		.value("TopAbs_WIRE", TopAbs_ShapeEnum::TopAbs_WIRE)
		.value("TopAbs_EDGE", TopAbs_ShapeEnum::TopAbs_EDGE)
		.value("TopAbs_VERTEX", TopAbs_ShapeEnum::TopAbs_VERTEX)
		.value("TopAbs_SHAPE", TopAbs_ShapeEnum::TopAbs_SHAPE)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopAbs.hxx
	py::class_<TopAbs, std::unique_ptr<TopAbs, Deleter<TopAbs>>> cls_TopAbs(mod, "TopAbs", "This package gives resources for Topology oriented applications such as : Topological Data Structure, Topological Algorithms.");
	cls_TopAbs.def(py::init<>());
	cls_TopAbs.def_static("Compose_", (TopAbs_Orientation (*)(const TopAbs_Orientation, const TopAbs_Orientation)) &TopAbs::Compose, "Compose the Orientation <Or1> and <Or2>. This composition is not symmetric (if you switch <Or1> and <Or2> the result is different). It assumes that <Or1> is the Orientation of a Shape S1 containing a Shape S2 of Orientation Or2. The result is the cumulated orientation of S2 in S1. The composition law is :", py::arg("Or1"), py::arg("Or2"));
	cls_TopAbs.def_static("Reverse_", (TopAbs_Orientation (*)(const TopAbs_Orientation)) &TopAbs::Reverse, "xchanges the interior/exterior status of the two sides. This is what happens when the sense of direction is reversed. The following rules apply:", py::arg("Or"));
	cls_TopAbs.def_static("Complement_", (TopAbs_Orientation (*)(const TopAbs_Orientation)) &TopAbs::Complement, "Reverses the interior/exterior status of each side of the object. So, to take the complement of an object means to reverse the interior/exterior status of its boundary, i.e. inside becomes outside. The method returns the complementary orientation, following the rules in the table below: FORWARD REVERSED REVERSED FORWARD INTERNAL EXTERNAL EXTERNAL INTERNAL", py::arg("Or"));
	cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_ShapeEnum, Standard_OStream &)) &TopAbs::Print, "Prints the name of Shape type as a String on the Stream.", py::arg("theShapeType"), py::arg("theStream"));
	cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_Orientation, Standard_OStream &)) &TopAbs::Print, "Prints the name of the Orientation as a String on the Stream.", py::arg("theOrientation"), py::arg("theStream"));
	cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_State, Standard_OStream &)) &TopAbs::Print, "Prints the name of the State <St> as a String on the Stream <S> and returns <S>.", py::arg("St"), py::arg("S"));
	cls_TopAbs.def_static("ShapeTypeToString_", (Standard_CString (*)(TopAbs_ShapeEnum)) &TopAbs::ShapeTypeToString, "Returns the string name for a given shape type.", py::arg("theType"));
	cls_TopAbs.def_static("ShapeTypeFromString_", (TopAbs_ShapeEnum (*)(Standard_CString)) &TopAbs::ShapeTypeFromString, "Returns the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"));
	cls_TopAbs.def_static("ShapeTypeFromString_", (Standard_Boolean (*)(Standard_CString, TopAbs_ShapeEnum &)) &TopAbs::ShapeTypeFromString, "Determines the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"), py::arg("theType"));
	cls_TopAbs.def_static("ShapeOrientationToString_", (Standard_CString (*)(TopAbs_Orientation)) &TopAbs::ShapeOrientationToString, "Returns the string name for a given shape orientation.", py::arg("theOrientation"));


}
