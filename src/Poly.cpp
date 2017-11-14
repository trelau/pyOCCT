#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <Poly_Triangle.hxx>
#include <NCollection_Array1.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include <Standard_Transient.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <TShort_Array1OfShortReal.hxx>
#include <gp_Dir.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Poly_Polygon3D.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Poly_Polygon2D.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Poly_ListOfTriangulation.hxx>
#include <Poly_Connect.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <gp_XY.hxx>
#include <Poly.hxx>
#include <Poly_CoherentTriangle.hxx>
#include <Poly_CoherentLink.hxx>
#include <Poly_CoherentTriangulation.hxx>
#include <gp_XYZ.hxx>
#include <Poly_CoherentNode.hxx>
#include <Poly_CoherentTriPtr.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>
#include <Poly_HArray1OfTriangle.hxx>
#include <Poly_MakeLoops.hxx>

PYBIND11_MODULE(Poly, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TShort");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_MakeLoops.hxx
	mod.def("HashCode", (Standard_Integer (*)(const Poly_MakeLoops::Link &, int)) &HashCode, "HashCode method is needed for maps", py::arg("theKey"), py::arg("theLimit"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_MakeLoops.hxx
	mod.def("IsEqual", (Standard_Boolean (*)(const Poly_MakeLoops::Link &, const Poly_MakeLoops::Link &)) &IsEqual, "IsEqual method is needed for maps", py::arg("theKey1"), py::arg("theKey2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_Triangle.hxx
	py::class_<Poly_Triangle, std::unique_ptr<Poly_Triangle, Deleter<Poly_Triangle>>> cls_Poly_Triangle(mod, "Poly_Triangle", "Describes a component triangle of a triangulation (Poly_Triangulation object). A Triangle is defined by a triplet of nodes. Each node is an index in the table of nodes specific to an existing triangulation of a shape, and represents a point on the surface.");
	cls_Poly_Triangle.def(py::init<>());
	cls_Poly_Triangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("N1"), py::arg("N2"), py::arg("N3"));
	cls_Poly_Triangle.def("Set", (void (Poly_Triangle::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_Triangle::Set, "Sets the value of the three nodes of this triangle to N1, N2 and N3 respectively.", py::arg("N1"), py::arg("N2"), py::arg("N3"));
	cls_Poly_Triangle.def("Set", (void (Poly_Triangle::*)(const Standard_Integer, const Standard_Integer)) &Poly_Triangle::Set, "Sets the value of the Indexth node of this triangle to Node. Raises OutOfRange if Index is not in 1,2,3", py::arg("Index"), py::arg("Node"));
	cls_Poly_Triangle.def("Get", (void (Poly_Triangle::*)(Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Poly_Triangle::Get, "Returns the node indices of this triangle in N1, N2 and N3.", py::arg("N1"), py::arg("N2"), py::arg("N3"));
	cls_Poly_Triangle.def("Value", (Standard_Integer (Poly_Triangle::*)(const Standard_Integer) const ) &Poly_Triangle::Value, "Get the node of given Index. Raises OutOfRange from Standard if Index is not in 1,2,3", py::arg("Index"));
	cls_Poly_Triangle.def("__call__", (Standard_Integer (Poly_Triangle::*)(const Standard_Integer) const ) &Poly_Triangle::operator(), py::is_operator(), "None", py::arg("Index"));
	cls_Poly_Triangle.def("ChangeValue", (Standard_Integer & (Poly_Triangle::*)(const Standard_Integer)) &Poly_Triangle::ChangeValue, "Get the node of given Index. Raises OutOfRange if Index is not in 1,2,3", py::arg("Index"));
	cls_Poly_Triangle.def("__call__", (Standard_Integer & (Poly_Triangle::*)(const Standard_Integer)) &Poly_Triangle::operator(), py::is_operator(), "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_Triangulation.hxx
	py::class_<Poly_Triangulation, opencascade::handle<Poly_Triangulation>, Standard_Transient> cls_Poly_Triangulation(mod, "Poly_Triangulation", "Provides a triangulation for a surface, a set of surfaces, or more generally a shape. A triangulation consists of an approximate representation of the actual shape, using a collection of points and triangles. The points are located on the surface. The edges of the triangles connect adjacent points with a straight line that approximates the true curve on the surface. A triangulation comprises: - A table of 3D nodes (3D points on the surface). - A table of triangles. Each triangle (Poly_Triangle object) comprises a triplet of indices in the table of 3D nodes specific to the triangulation. - A table of 2D nodes (2D points), parallel to the table of 3D nodes. This table is optional. If it exists, the coordinates of a 2D point are the (u, v) parameters of the corresponding 3D point on the surface approximated by the triangulation. - A deflection (optional), which maximizes the distance from a point on the surface to the corresponding point on its approximate triangulation. In many cases, algorithms do not need to work with the exact representation of a surface. A triangular representation induces simpler and more robust adjusting, faster performances, and the results are as good. This is a Transient class.");
	cls_Poly_Triangulation.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("nbNodes"), py::arg("nbTriangles"), py::arg("UVNodes"));
	cls_Poly_Triangulation.def(py::init<const TColgp_Array1OfPnt &, const Poly_Array1OfTriangle &>(), py::arg("Nodes"), py::arg("Triangles"));
	cls_Poly_Triangulation.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const Poly_Array1OfTriangle &>(), py::arg("Nodes"), py::arg("UVNodes"), py::arg("Triangles"));
	cls_Poly_Triangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));
	cls_Poly_Triangulation.def_static("get_type_name_", (const char * (*)()) &Poly_Triangulation::get_type_name, "None");
	cls_Poly_Triangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Triangulation::get_type_descriptor, "None");
	cls_Poly_Triangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Triangulation::*)() const ) &Poly_Triangulation::DynamicType, "None");
	cls_Poly_Triangulation.def("Copy", (opencascade::handle<Poly_Triangulation> (Poly_Triangulation::*)() const ) &Poly_Triangulation::Copy, "Creates full copy of current triangulation");
	cls_Poly_Triangulation.def("Deflection", (Standard_Real (Poly_Triangulation::*)() const ) &Poly_Triangulation::Deflection, "Returns the deflection of this triangulation.");
	cls_Poly_Triangulation.def("Deflection", (void (Poly_Triangulation::*)(const Standard_Real)) &Poly_Triangulation::Deflection, "Sets the deflection of this triangulation to theDeflection. See more on deflection in Polygon2D", py::arg("theDeflection"));
	cls_Poly_Triangulation.def("RemoveUVNodes", (void (Poly_Triangulation::*)()) &Poly_Triangulation::RemoveUVNodes, "Deallocates the UV nodes.");
	cls_Poly_Triangulation.def("NbNodes", (Standard_Integer (Poly_Triangulation::*)() const ) &Poly_Triangulation::NbNodes, "Returns the number of nodes for this triangulation.");
	cls_Poly_Triangulation.def("NbTriangles", (Standard_Integer (Poly_Triangulation::*)() const ) &Poly_Triangulation::NbTriangles, "Returns the number of triangles for this triangulation.");
	cls_Poly_Triangulation.def("HasUVNodes", (Standard_Boolean (Poly_Triangulation::*)() const ) &Poly_Triangulation::HasUVNodes, "Returns Standard_True if 2D nodes are associated with 3D nodes for this triangulation.");
	cls_Poly_Triangulation.def("Nodes", (const TColgp_Array1OfPnt & (Poly_Triangulation::*)() const ) &Poly_Triangulation::Nodes, "Returns the table of 3D nodes (3D points) for this triangulation.");
	cls_Poly_Triangulation.def("ChangeNodes", (TColgp_Array1OfPnt & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeNodes, "Returns the table of 3D nodes (3D points) for this triangulation. The returned array is shared. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
	cls_Poly_Triangulation.def("Node", (const gp_Pnt & (Poly_Triangulation::*)(const Standard_Integer) const ) &Poly_Triangulation::Node, "Returns node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("ChangeNode", (gp_Pnt & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeNode, "Give access to the node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("UVNodes", (const TColgp_Array1OfPnt2d & (Poly_Triangulation::*)() const ) &Poly_Triangulation::UVNodes, "Returns the table of 2D nodes (2D points) associated with each 3D node of this triangulation. The function HasUVNodes checks if 2D nodes are associated with the 3D nodes of this triangulation. Const reference on the 2d nodes values.");
	cls_Poly_Triangulation.def("ChangeUVNodes", (TColgp_Array1OfPnt2d & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeUVNodes, "Returns the table of 2D nodes (2D points) associated with each 3D node of this triangulation. Function ChangeUVNodes shares the returned array. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
	cls_Poly_Triangulation.def("UVNode", (const gp_Pnt2d & (Poly_Triangulation::*)(const Standard_Integer) const ) &Poly_Triangulation::UVNode, "Returns UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("ChangeUVNode", (gp_Pnt2d & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeUVNode, "Give access to the UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("Triangles", (const Poly_Array1OfTriangle & (Poly_Triangulation::*)() const ) &Poly_Triangulation::Triangles, "Returns the table of triangles for this triangulation.");
	cls_Poly_Triangulation.def("ChangeTriangles", (Poly_Array1OfTriangle & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeTriangles, "Returns the table of triangles for this triangulation. Function ChangeUVNodes shares the returned array. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
	cls_Poly_Triangulation.def("Triangle", (const Poly_Triangle & (Poly_Triangulation::*)(const Standard_Integer) const ) &Poly_Triangulation::Triangle, "Returns triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("ChangeTriangle", (Poly_Triangle & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeTriangle, "Give access to the triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("SetNormals", (void (Poly_Triangulation::*)(const opencascade::handle<TShort_HArray1OfShortReal> &)) &Poly_Triangulation::SetNormals, "Sets the table of node normals. raises exception if length of theNormals != 3*NbNodes", py::arg("theNormals"));
	cls_Poly_Triangulation.def("Normals", (const TShort_Array1OfShortReal & (Poly_Triangulation::*)() const ) &Poly_Triangulation::Normals, "Returns the table of node normals.");
	cls_Poly_Triangulation.def("ChangeNormals", (TShort_Array1OfShortReal & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeNormals, "Gives access to the table of node normals.");
	cls_Poly_Triangulation.def("HasNormals", (Standard_Boolean (Poly_Triangulation::*)() const ) &Poly_Triangulation::HasNormals, "Returns Standard_True if nodal normals are defined.");
	cls_Poly_Triangulation.def("Normal", (const gp_Dir (Poly_Triangulation::*)(const Standard_Integer) const ) &Poly_Triangulation::Normal, "Returns normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"));
	cls_Poly_Triangulation.def("SetNormal", (void (Poly_Triangulation::*)(const Standard_Integer, const gp_Dir &)) &Poly_Triangulation::SetNormal, "Changes normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"), py::arg("theNormal"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_Polygon3D.hxx
	py::class_<Poly_Polygon3D, opencascade::handle<Poly_Polygon3D>, Standard_Transient> cls_Poly_Polygon3D(mod, "Poly_Polygon3D", "This class Provides a polygon in 3D space. It is generally an approximate representation of a curve. A Polygon3D is defined by a table of nodes. Each node is a 3D point. If the polygon is closed, the point of closure is repeated at the end of the table of nodes. If the polygon is an approximate representation of a curve, you can associate with each of its nodes the value of the parameter of the corresponding point on the curve.");
	cls_Poly_Polygon3D.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Nodes"));
	cls_Poly_Polygon3D.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Nodes"), py::arg("Parameters"));
	cls_Poly_Polygon3D.def("Copy", (opencascade::handle<Poly_Polygon3D> (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::Copy, "Creates a copy of current polygon");
	cls_Poly_Polygon3D.def("Deflection", (Standard_Real (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::Deflection, "Returns the deflection of this polygon");
	cls_Poly_Polygon3D.def("Deflection", (void (Poly_Polygon3D::*)(const Standard_Real)) &Poly_Polygon3D::Deflection, "Sets the deflection of this polygon to D. See more on deflection in Poly_Polygon2D", py::arg("D"));
	cls_Poly_Polygon3D.def("NbNodes", (Standard_Integer (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::NbNodes, "Returns the number of nodes in this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle the function NbNodes returns 4.");
	cls_Poly_Polygon3D.def("Nodes", (const TColgp_Array1OfPnt & (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::Nodes, "Returns the table of nodes for this polygon.");
	cls_Poly_Polygon3D.def("HasParameters", (Standard_Boolean (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::HasParameters, "Returns the table of the parameters associated with each node in this polygon. HasParameters function checks if parameters are associated with the nodes of this polygon.");
	cls_Poly_Polygon3D.def("Parameters", (const TColStd_Array1OfReal & (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::Parameters, "Returns true if parameters are associated with the nodes in this polygon.");
	cls_Poly_Polygon3D.def("ChangeParameters", (TColStd_Array1OfReal & (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::ChangeParameters, "Returns the table of the parameters associated with each node in this polygon. ChangeParameters function returnes the array as shared. Therefore if the table is selected by reference you can, by simply modifying it, directly modify the data structure of this polygon.");
	cls_Poly_Polygon3D.def_static("get_type_name_", (const char * (*)()) &Poly_Polygon3D::get_type_name, "None");
	cls_Poly_Polygon3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Polygon3D::get_type_descriptor, "None");
	cls_Poly_Polygon3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Polygon3D::*)() const ) &Poly_Polygon3D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_PolygonOnTriangulation.hxx
	py::class_<Poly_PolygonOnTriangulation, opencascade::handle<Poly_PolygonOnTriangulation>, Standard_Transient> cls_Poly_PolygonOnTriangulation(mod, "Poly_PolygonOnTriangulation", "This class provides a polygon in 3D space, based on the triangulation of a surface. It may be the approximate representation of a curve on the surface, or more generally the shape. A PolygonOnTriangulation is defined by a table of nodes. Each node is an index in the table of nodes specific to a triangulation, and represents a point on the surface. If the polygon is closed, the index of the point of closure is repeated at the end of the table of nodes. If the polygon is an approximate representation of a curve on a surface, you can associate with each of its nodes the value of the parameter of the corresponding point on the curve.represents a 3d Polygon");
	cls_Poly_PolygonOnTriangulation.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("Nodes"));
	cls_Poly_PolygonOnTriangulation.def(py::init<const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &>(), py::arg("Nodes"), py::arg("Parameters"));
	cls_Poly_PolygonOnTriangulation.def("Copy", (opencascade::handle<Poly_PolygonOnTriangulation> (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::Copy, "Creates a copy of current polygon");
	cls_Poly_PolygonOnTriangulation.def("Deflection", (Standard_Real (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::Deflection, "Returns the deflection of this polygon");
	cls_Poly_PolygonOnTriangulation.def("Deflection", (void (Poly_PolygonOnTriangulation::*)(const Standard_Real)) &Poly_PolygonOnTriangulation::Deflection, "Sets the deflection of this polygon to D. See more on deflection in Poly_Polygones2D.", py::arg("D"));
	cls_Poly_PolygonOnTriangulation.def("NbNodes", (Standard_Integer (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::NbNodes, "Returns the number of nodes for this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle, the function NbNodes returns 4.");
	cls_Poly_PolygonOnTriangulation.def("Nodes", (const TColStd_Array1OfInteger & (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::Nodes, "Returns the table of nodes for this polygon. A node value is an index in the table of nodes specific to an existing triangulation of a shape.");
	cls_Poly_PolygonOnTriangulation.def("HasParameters", (Standard_Boolean (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::HasParameters, "Returns true if parameters are associated with the nodes in this polygon.");
	cls_Poly_PolygonOnTriangulation.def("Parameters", (opencascade::handle<TColStd_HArray1OfReal> (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::Parameters, "Returns the table of the parameters associated with each node in this polygon. Warning Use the function HasParameters to check if parameters are associated with the nodes in this polygon.");
	cls_Poly_PolygonOnTriangulation.def_static("get_type_name_", (const char * (*)()) &Poly_PolygonOnTriangulation::get_type_name, "None");
	cls_Poly_PolygonOnTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_PolygonOnTriangulation::get_type_descriptor, "None");
	cls_Poly_PolygonOnTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_PolygonOnTriangulation::*)() const ) &Poly_PolygonOnTriangulation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_Polygon2D.hxx
	py::class_<Poly_Polygon2D, opencascade::handle<Poly_Polygon2D>, Standard_Transient> cls_Poly_Polygon2D(mod, "Poly_Polygon2D", "Provides a polygon in 2D space (for example, in the parametric space of a surface). It is generally an approximate representation of a curve. A Polygon2D is defined by a table of nodes. Each node is a 2D point. If the polygon is closed, the point of closure is repeated at the end of the table of nodes.");
	cls_Poly_Polygon2D.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("Nodes"));
	cls_Poly_Polygon2D.def("Deflection", (Standard_Real (Poly_Polygon2D::*)() const ) &Poly_Polygon2D::Deflection, "Returns the deflection of this polygon. Deflection is used in cases where the polygon is an approximate representation of a curve. Deflection represents the maximum distance permitted between any point on the curve and the corresponding point on the polygon. By default the deflection value is equal to 0. An algorithm using this 2D polygon with a deflection value equal to 0 considers that it is working with a true polygon and not with an approximate representation of a curve. The Deflection function is used to modify the deflection value of this polygon. The deflection value can be used by any algorithm working with 2D polygons. For example: - An algorithm may use a unique deflection value for all its polygons. In this case it is not necessary to use the Deflection function. - Or an algorithm may want to attach a different deflection to each polygon. In this case, the Deflection function is used to set a value on each polygon, and later to fetch the value.");
	cls_Poly_Polygon2D.def("Deflection", (void (Poly_Polygon2D::*)(const Standard_Real)) &Poly_Polygon2D::Deflection, "Sets the deflection of this polygon to D", py::arg("D"));
	cls_Poly_Polygon2D.def("NbNodes", (Standard_Integer (Poly_Polygon2D::*)() const ) &Poly_Polygon2D::NbNodes, "Returns the number of nodes in this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle, the function NbNodes returns 4.");
	cls_Poly_Polygon2D.def("Nodes", (const TColgp_Array1OfPnt2d & (Poly_Polygon2D::*)() const ) &Poly_Polygon2D::Nodes, "Returns the table of nodes for this polygon.");
	cls_Poly_Polygon2D.def_static("get_type_name_", (const char * (*)()) &Poly_Polygon2D::get_type_name, "None");
	cls_Poly_Polygon2D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Polygon2D::get_type_descriptor, "None");
	cls_Poly_Polygon2D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Polygon2D::*)() const ) &Poly_Polygon2D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_Connect.hxx
	py::class_<Poly_Connect, std::unique_ptr<Poly_Connect, Deleter<Poly_Connect>>> cls_Poly_Connect(mod, "Poly_Connect", "Provides an algorithm to explore, inside a triangulation, the adjacency data for a node or a triangle. Adjacency data for a node consists of triangles which contain the node. Adjacency data for a triangle consists of: - the 3 adjacent triangles which share an edge of the triangle, - and the 3 nodes which are the other nodes of these adjacent triangles. Example Inside a triangulation, a triangle T has nodes n1, n2 and n3. It has adjacent triangles AT1, AT2 and AT3 where: - AT1 shares the nodes n2 and n3, - AT2 shares the nodes n3 and n1, - AT3 shares the nodes n1 and n2. It has adjacent nodes an1, an2 and an3 where: - an1 is the third node of AT1, - an2 is the third node of AT2, - an3 is the third node of AT3. So triangle AT1 is composed of nodes n2, n3 and an1. There are two ways of using this algorithm. - From a given node you can look for one triangle that passes through the node, then look for the triangles adjacent to this triangle, then the adjacent nodes. You can thus explore the triangulation step by step (functions Triangle, Triangles and Nodes). - From a given node you can look for all the triangles that pass through the node (iteration method, using the functions Initialize, More, Next and Value). A Connect object can be seen as a tool which analyzes a triangulation and translates it into a series of triangles. By doing this, it provides an interface with other tools and applications working on basic triangles, and which do not work directly with a Poly_Triangulation.");
	cls_Poly_Connect.def(py::init<>());
	cls_Poly_Connect.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));
	cls_Poly_Connect.def("Load", (void (Poly_Connect::*)(const opencascade::handle<Poly_Triangulation> &)) &Poly_Connect::Load, "Initialize the algorithm to explore the adjacency data of nodes or triangles for the triangulation theTriangulation.", py::arg("theTriangulation"));
	cls_Poly_Connect.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (Poly_Connect::*)() const ) &Poly_Connect::Triangulation, "Returns the triangulation analyzed by this tool.");
	cls_Poly_Connect.def("Triangle", (Standard_Integer (Poly_Connect::*)(const Standard_Integer) const ) &Poly_Connect::Triangle, "Returns the index of a triangle containing the node at index N in the nodes table specific to the triangulation analyzed by this tool", py::arg("N"));
	cls_Poly_Connect.def("Triangles", (void (Poly_Connect::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Poly_Connect::Triangles, "Returns in t1, t2 and t3, the indices of the 3 triangles adjacent to the triangle at index T in the triangles table specific to the triangulation analyzed by this tool. Warning Null indices are returned when there are fewer than 3 adjacent triangles.", py::arg("T"), py::arg("t1"), py::arg("t2"), py::arg("t3"));
	cls_Poly_Connect.def("Nodes", (void (Poly_Connect::*)(const Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &) const ) &Poly_Connect::Nodes, "Returns, in n1, n2 and n3, the indices of the 3 nodes adjacent to the triangle referenced at index T in the triangles table specific to the triangulation analyzed by this tool. Warning Null indices are returned when there are fewer than 3 adjacent nodes.", py::arg("T"), py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_Poly_Connect.def("Initialize", (void (Poly_Connect::*)(const Standard_Integer)) &Poly_Connect::Initialize, "Initializes an iterator to search for all the triangles containing the node referenced at index N in the nodes table, for the triangulation analyzed by this tool. The iterator is managed by the following functions: - More, which checks if there are still elements in the iterator - Next, which positions the iterator on the next element - Value, which returns the current element. The use of such an iterator provides direct access to the triangles around a particular node, i.e. it avoids iterating on all the component triangles of a triangulation. Example Poly_Connect C(Tr); for (C.Initialize(n1);C.More();C.Next()) { t = C.Value(); }", py::arg("N"));
	cls_Poly_Connect.def("More", (Standard_Boolean (Poly_Connect::*)() const ) &Poly_Connect::More, "Returns true if there is another element in the iterator defined with the function Initialize (i.e. if there is another triangle containing the given node).");
	cls_Poly_Connect.def("Next", (void (Poly_Connect::*)()) &Poly_Connect::Next, "Advances the iterator defined with the function Initialize to access the next triangle. Note: There is no action if the iterator is empty (i.e. if the function More returns false).-");
	cls_Poly_Connect.def("Value", (Standard_Integer (Poly_Connect::*)() const ) &Poly_Connect::Value, "Returns the index of the current triangle to which the iterator, defined with the function Initialize, points. This is an index in the triangles table specific to the triangulation analyzed by this tool");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly.hxx
	py::class_<Poly, std::unique_ptr<Poly, Deleter<Poly>>> cls_Poly(mod, "Poly", "This package provides classes and services to handle :");
	cls_Poly.def(py::init<>());
	cls_Poly.def_static("Catenate_", (opencascade::handle<Poly_Triangulation> (*)(const Poly_ListOfTriangulation &)) &Poly::Catenate, "Computes and stores the link from nodes to triangles and from triangles to neighbouring triangles. This tool is obsolete, replaced by Poly_CoherentTriangulation Algorithm to make minimal loops in a graph Join several triangulations to one new triangulation object. The new triangulation is just a mechanical sum of input triangulations, without node sharing. UV coordinates are dropped in the result.", py::arg("lstTri"));
	cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Triangulation> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); }, py::arg("T"), py::arg("OS"));
	cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Triangulation> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the triangulation <T> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("T"), py::arg("OS"), py::arg("Compact"));
	cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Polygon3D> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); }, py::arg("P"), py::arg("OS"));
	cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Polygon3D> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the 3D polygon <P> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("P"), py::arg("OS"), py::arg("Compact"));
	cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Polygon2D> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); }, py::arg("P"), py::arg("OS"));
	cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Polygon2D> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the 2D polygon <P> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("P"), py::arg("OS"), py::arg("Compact"));
	// FIXME cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Triangulation> &, Standard_OStream &)) &Poly::Dump, "Dumps the triangulation. This is a call to the previous method with Comapct set to False.", py::arg("T"), py::arg("OS"));
	// FIXME cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Polygon3D> &, Standard_OStream &)) &Poly::Dump, "Dumps the 3D polygon. This is a call to the previous method with Comapct set to False.", py::arg("P"), py::arg("OS"));
	// FIXME cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Polygon2D> &, Standard_OStream &)) &Poly::Dump, "Dumps the 2D polygon. This is a call to the previous method with Comapct set to False.", py::arg("P"), py::arg("OS"));
	cls_Poly.def_static("ReadTriangulation_", (opencascade::handle<Poly_Triangulation> (*)(Standard_IStream &)) &Poly::ReadTriangulation, "Reads a triangulation from the stream <IS>.", py::arg("IS"));
	cls_Poly.def_static("ReadPolygon3D_", (opencascade::handle<Poly_Polygon3D> (*)(Standard_IStream &)) &Poly::ReadPolygon3D, "Reads a 3d polygon from the stream <IS>.", py::arg("IS"));
	cls_Poly.def_static("ReadPolygon2D_", (opencascade::handle<Poly_Polygon2D> (*)(Standard_IStream &)) &Poly::ReadPolygon2D, "Reads a 2D polygon from the stream <IS>.", py::arg("IS"));
	cls_Poly.def_static("ComputeNormals_", (void (*)(const opencascade::handle<Poly_Triangulation> &)) &Poly::ComputeNormals, "Compute node normals for face triangulation as mean normal of surrounding triangles", py::arg("Tri"));
	cls_Poly.def_static("PointOnTriangle_", (Standard_Real (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, gp_XY &)) &Poly::PointOnTriangle, "Computes parameters of the point P on triangle defined by points P1, P2, and P3, in 2d. The parameters U and V are defined so that P = P1 + U * (P2 - P1) + V * (P3 - P1), with U >= 0, V >= 0, U + V <= 1. If P is located outside of triangle, or triangle is degenerated, the returned parameters correspond to closest point, and returned value is square of the distance from original point to triangle (0 if point is inside).", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P"), py::arg("UV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangle.hxx
	py::class_<Poly_CoherentTriangle, std::unique_ptr<Poly_CoherentTriangle, Deleter<Poly_CoherentTriangle>>> cls_Poly_CoherentTriangle(mod, "Poly_CoherentTriangle", "Data class used in Poly_CoherentTriangultion. Implements a triangle with references to its neighbours.");
	cls_Poly_CoherentTriangle.def(py::init<>());
	cls_Poly_CoherentTriangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));
	cls_Poly_CoherentTriangle.def("Node", (Standard_Integer (Poly_CoherentTriangle::*)(const Standard_Integer) const ) &Poly_CoherentTriangle::Node, "Query the node index in the position given by the parameter 'ind'", py::arg("ind"));
	cls_Poly_CoherentTriangle.def("IsEmpty", (Standard_Boolean (Poly_CoherentTriangle::*)() const ) &Poly_CoherentTriangle::IsEmpty, "Query if this is a valid triangle.");
	cls_Poly_CoherentTriangle.def("SetConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(const Standard_Integer, Poly_CoherentTriangle &)) &Poly_CoherentTriangle::SetConnection, "Create connection with another triangle theTri. This method creates both connections: in this triangle and in theTri. You do not need to call the same method on triangle theTr.", py::arg("iConn"), py::arg("theTr"));
	cls_Poly_CoherentTriangle.def("SetConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangle::SetConnection, "Create connection with another triangle theTri. This method creates both connections: in this triangle and in theTri. This method is slower than the previous one, because it makes analysis what sides of both triangles are connected.", py::arg("theTri"));
	cls_Poly_CoherentTriangle.def("RemoveConnection", (void (Poly_CoherentTriangle::*)(const Standard_Integer)) &Poly_CoherentTriangle::RemoveConnection, "Remove the connection with the given index.", py::arg("iConn"));
	cls_Poly_CoherentTriangle.def("RemoveConnection", (Standard_Boolean (Poly_CoherentTriangle::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangle::RemoveConnection, "Remove the connection with the given Triangle.", py::arg("theTri"));
	cls_Poly_CoherentTriangle.def("NConnections", (Standard_Integer (Poly_CoherentTriangle::*)() const ) &Poly_CoherentTriangle::NConnections, "Query the number of connected triangles.");
	cls_Poly_CoherentTriangle.def("GetConnectedNode", (Standard_Integer (Poly_CoherentTriangle::*)(const Standard_Integer) const ) &Poly_CoherentTriangle::GetConnectedNode, "Query the connected node on the given side. Returns -1 if there is no connection on the specified side.", py::arg("iConn"));
	cls_Poly_CoherentTriangle.def("GetConnectedTri", (const Poly_CoherentTriangle * (Poly_CoherentTriangle::*)(const Standard_Integer) const ) &Poly_CoherentTriangle::GetConnectedTri, "Query the connected triangle on the given side. Returns NULL if there is no connection on the specified side.", py::arg("iConn"));
	cls_Poly_CoherentTriangle.def("GetLink", (const Poly_CoherentLink * (Poly_CoherentTriangle::*)(const Standard_Integer) const ) &Poly_CoherentTriangle::GetLink, "Query the Link associate with the given side of the Triangle. May return NULL if there are no links in the triangulation.", py::arg("iLink"));
	cls_Poly_CoherentTriangle.def("FindConnection", (Standard_Integer (Poly_CoherentTriangle::*)(const Poly_CoherentTriangle &) const ) &Poly_CoherentTriangle::FindConnection, "Retuns the index of the connection with the given triangle, or -1 if not found.", py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangulation.hxx
	py::class_<Poly_CoherentTriangulation, opencascade::handle<Poly_CoherentTriangulation>, Standard_Transient> cls_Poly_CoherentTriangulation(mod, "Poly_CoherentTriangulation", "Triangulation structure that allows to: Store the connectivity of each triangle with up to 3 neighbouring ones and with the corresponding 3rd nodes on them, Store the connectivity of each node with all triangles that share this node Add nodes and triangles to the structure, Find all triangles sharing a single or a couple of nodes Remove triangles from structure Optionally create Links between pairs of nodes according to the current triangulation. Convert from/to Poly_Triangulation structure.");
	cls_Poly_CoherentTriangulation.def(py::init<>());
	cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));
	cls_Poly_CoherentTriangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theTriangulation"), py::arg("theAlloc"));
	cls_Poly_CoherentTriangulation.def("GetTriangulation", (opencascade::handle<Poly_Triangulation> (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::GetTriangulation, "Create an instance of Poly_Triangulation from this object.");
	cls_Poly_CoherentTriangulation.def("RemoveDegenerated", [](Poly_CoherentTriangulation &self, const Standard_Real a0) -> Standard_Boolean { return self.RemoveDegenerated(a0); }, py::arg("theTol"));
	cls_Poly_CoherentTriangulation.def("RemoveDegenerated", (Standard_Boolean (Poly_CoherentTriangulation::*)(const Standard_Real, NCollection_List<Poly_CoherentTriangulation::TwoIntegers> *)) &Poly_CoherentTriangulation::RemoveDegenerated, "Find and remove degenerated triangles in Triangulation.", py::arg("theTol"), py::arg("pLstRemovedNode"));
	cls_Poly_CoherentTriangulation.def("GetFreeNodes", (Standard_Boolean (Poly_CoherentTriangulation::*)(NCollection_List<Standard_Integer> &) const ) &Poly_CoherentTriangulation::GetFreeNodes, "Create a list of free nodes. These nodes may appear as a result of any custom mesh decimation or RemoveDegenerated() call. This analysis is necessary if you support additional data structures based on the triangulation (e.g., edges on the surface boundary).", py::arg("lstNodes"));
	cls_Poly_CoherentTriangulation.def("MaxNode", (Standard_Integer (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::MaxNode, "Query the index of the last node in the triangulation");
	cls_Poly_CoherentTriangulation.def("MaxTriangle", (Standard_Integer (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::MaxTriangle, "Query the index of the last triangle in the triangulation");
	cls_Poly_CoherentTriangulation.def("SetDeflection", (void (Poly_CoherentTriangulation::*)(const Standard_Real)) &Poly_CoherentTriangulation::SetDeflection, "Set the Deflection value as the parameter of the given triangulation.", py::arg("theDefl"));
	cls_Poly_CoherentTriangulation.def("Deflection", (Standard_Real (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::Deflection, "Query the Deflection parameter (default value 0. -- if never initialized)");
	cls_Poly_CoherentTriangulation.def("SetNode", [](Poly_CoherentTriangulation &self, const gp_XYZ & a0) -> Standard_Integer { return self.SetNode(a0); }, py::arg("thePnt"));
	cls_Poly_CoherentTriangulation.def("SetNode", (Standard_Integer (Poly_CoherentTriangulation::*)(const gp_XYZ &, const Standard_Integer)) &Poly_CoherentTriangulation::SetNode, "Initialize a node", py::arg("thePnt"), py::arg("iN"));
	cls_Poly_CoherentTriangulation.def("Node", (const Poly_CoherentNode & (Poly_CoherentTriangulation::*)(const Standard_Integer) const ) &Poly_CoherentTriangulation::Node, "Get the node at the given index 'i'.", py::arg("i"));
	cls_Poly_CoherentTriangulation.def("ChangeNode", (Poly_CoherentNode & (Poly_CoherentTriangulation::*)(const Standard_Integer)) &Poly_CoherentTriangulation::ChangeNode, "Get the node at the given index 'i'.", py::arg("i"));
	cls_Poly_CoherentTriangulation.def("NNodes", (Standard_Integer (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::NNodes, "Query the total number of active nodes (i.e. nodes used by 1 or more triangles)");
	cls_Poly_CoherentTriangulation.def("Triangle", (const Poly_CoherentTriangle & (Poly_CoherentTriangulation::*)(const Standard_Integer) const ) &Poly_CoherentTriangulation::Triangle, "Get the triangle at the given index 'i'.", py::arg("i"));
	cls_Poly_CoherentTriangulation.def("NTriangles", (Standard_Integer (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::NTriangles, "Query the total number of active triangles (i.e. triangles that refer nodes, non-empty ones)");
	cls_Poly_CoherentTriangulation.def("NLinks", (Standard_Integer (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::NLinks, "Query the total number of active Links.");
	cls_Poly_CoherentTriangulation.def("RemoveTriangle", (Standard_Boolean (Poly_CoherentTriangulation::*)(Poly_CoherentTriangle &)) &Poly_CoherentTriangulation::RemoveTriangle, "Removal of a single triangle from the triangulation.", py::arg("theTr"));
	cls_Poly_CoherentTriangulation.def("RemoveLink", (void (Poly_CoherentTriangulation::*)(Poly_CoherentLink &)) &Poly_CoherentTriangulation::RemoveLink, "Removal of a single link from the triangulation.", py::arg("theLink"));
	cls_Poly_CoherentTriangulation.def("AddTriangle", (Poly_CoherentTriangle * (Poly_CoherentTriangulation::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_CoherentTriangulation::AddTriangle, "Add a triangle to the triangulation.", py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));
	cls_Poly_CoherentTriangulation.def("ReplaceNodes", (Standard_Boolean (Poly_CoherentTriangulation::*)(Poly_CoherentTriangle &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Poly_CoherentTriangulation::ReplaceNodes, "Replace nodes in the given triangle.", py::arg("theTriangle"), py::arg("iNode0"), py::arg("iNode1"), py::arg("iNode2"));
	cls_Poly_CoherentTriangulation.def("AddLink", (Poly_CoherentLink * (Poly_CoherentTriangulation::*)(const Poly_CoherentTriangle &, const Standard_Integer)) &Poly_CoherentTriangulation::AddLink, "Add a single link to triangulation, based on a triangle and its side index. This method does not check for coincidence with already present links.", py::arg("theTri"), py::arg("theConn"));
	// FIXME cls_Poly_CoherentTriangulation.def("FindTriangle", (Standard_Boolean (Poly_CoherentTriangulation::*)(const Poly_CoherentLink &, const Poly_CoherentTriangle *[2]) const ) &Poly_CoherentTriangulation::FindTriangle, "Find one or two triangles that share the given couple of nodes.", py::arg("theLink"), py::arg("pTri"));
	cls_Poly_CoherentTriangulation.def("ComputeLinks", (Standard_Integer (Poly_CoherentTriangulation::*)()) &Poly_CoherentTriangulation::ComputeLinks, "(Re)Calculate all links in this Triangulation.");
	cls_Poly_CoherentTriangulation.def("ClearLinks", (void (Poly_CoherentTriangulation::*)()) &Poly_CoherentTriangulation::ClearLinks, "Clear all Links data from the Triangulation data.");
	cls_Poly_CoherentTriangulation.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::Allocator, "Query the allocator of elements, this allocator can be used for other objects");
	cls_Poly_CoherentTriangulation.def("Clone", (opencascade::handle<Poly_CoherentTriangulation> (Poly_CoherentTriangulation::*)(const opencascade::handle<NCollection_BaseAllocator> &) const ) &Poly_CoherentTriangulation::Clone, "Create a copy of this Triangulation, using the given allocator.", py::arg("theAlloc"));
	// FIXME cls_Poly_CoherentTriangulation.def("Dump", (void (Poly_CoherentTriangulation::*)(Standard_OStream &) const ) &Poly_CoherentTriangulation::Dump, "Debugging output.", py::arg(""));
	cls_Poly_CoherentTriangulation.def_static("get_type_name_", (const char * (*)()) &Poly_CoherentTriangulation::get_type_name, "None");
	cls_Poly_CoherentTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_CoherentTriangulation::get_type_descriptor, "None");
	cls_Poly_CoherentTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_CoherentTriangulation::*)() const ) &Poly_CoherentTriangulation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentLink.hxx
	py::class_<Poly_CoherentLink, std::unique_ptr<Poly_CoherentLink, Deleter<Poly_CoherentLink>>> cls_Poly_CoherentLink(mod, "Poly_CoherentLink", "Link between two mesh nodes that is created by existing triangle(s). Keeps reference to the opposite node of each incident triangle. The referred node with index '0' is always on the left side of the link, the one with the index '1' is always on the right side. It is possible to find both incident triangles using the method Poly_CoherentTriangulation::FindTriangle(). Any Link can store an arbitrary pointer that is called Attribute.");
	cls_Poly_CoherentLink.def(py::init<>());
	cls_Poly_CoherentLink.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("iNode0"), py::arg("iNode1"));
	cls_Poly_CoherentLink.def(py::init<const Poly_CoherentTriangle &, Standard_Integer>(), py::arg("theTri"), py::arg("iSide"));
	cls_Poly_CoherentLink.def("Node", (Standard_Integer (Poly_CoherentLink::*)(const Standard_Integer) const ) &Poly_CoherentLink::Node, "Return the node index in the current triangulation.", py::arg("ind"));
	cls_Poly_CoherentLink.def("OppositeNode", (Standard_Integer (Poly_CoherentLink::*)(const Standard_Integer) const ) &Poly_CoherentLink::OppositeNode, "Return the opposite node (belonging to the left or right incident triangle) index in the current triangulation.", py::arg("ind"));
	cls_Poly_CoherentLink.def("GetAttribute", (Standard_Address (Poly_CoherentLink::*)() const ) &Poly_CoherentLink::GetAttribute, "Query the attribute of the Link.");
	cls_Poly_CoherentLink.def("SetAttribute", (void (Poly_CoherentLink::*)(const Standard_Address)) &Poly_CoherentLink::SetAttribute, "Set the attribute of the Link.", py::arg("theAtt"));
	cls_Poly_CoherentLink.def("IsEmpty", (Standard_Boolean (Poly_CoherentLink::*)() const ) &Poly_CoherentLink::IsEmpty, "Query the status of the link - if it is an invalid one. An invalid link has Node members equal to -1.");
	cls_Poly_CoherentLink.def("Nullify", (void (Poly_CoherentLink::*)()) &Poly_CoherentLink::Nullify, "Invalidate this Link.");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriPtr.hxx
	py::class_<Poly_CoherentTriPtr, std::unique_ptr<Poly_CoherentTriPtr, Deleter<Poly_CoherentTriPtr>>> cls_Poly_CoherentTriPtr(mod, "Poly_CoherentTriPtr", "Implementation of both list node for Poly_CoherentTriangle type and round double-linked list of these nodes.");
	cls_Poly_CoherentTriPtr.def(py::init<const Poly_CoherentTriangle &>(), py::arg("theTri"));
	cls_Poly_CoherentTriPtr.def("GetTriangle", (const Poly_CoherentTriangle & (Poly_CoherentTriPtr::*)() const ) &Poly_CoherentTriPtr::GetTriangle, "Query the stored pointer to Triangle.");
	cls_Poly_CoherentTriPtr.def("SetTriangle", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *)) &Poly_CoherentTriPtr::SetTriangle, "Initialize this instance with a pointer to triangle.", py::arg("pTri"));
	cls_Poly_CoherentTriPtr.def("Next", (Poly_CoherentTriPtr & (Poly_CoherentTriPtr::*)() const ) &Poly_CoherentTriPtr::Next, "Query the next pointer in the list.");
	cls_Poly_CoherentTriPtr.def("Previous", (Poly_CoherentTriPtr & (Poly_CoherentTriPtr::*)() const ) &Poly_CoherentTriPtr::Previous, "Query the previous pointer in the list.");
	cls_Poly_CoherentTriPtr.def("Append", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Append, "Append a pointer to triangle into the list after the current instance.", py::arg("pTri"), py::arg("theA"));
	cls_Poly_CoherentTriPtr.def("Prepend", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Prepend, "Prepend a pointer to triangle into the list before the current instance.", py::arg("pTri"), py::arg("theA"));
	cls_Poly_CoherentTriPtr.def_static("Remove_", (void (*)(Poly_CoherentTriPtr *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Remove, "Remove a pointer to triangle from its list.", py::arg("thePtr"), py::arg("theA"));
	cls_Poly_CoherentTriPtr.def_static("RemoveList_", (void (*)(Poly_CoherentTriPtr *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::RemoveList, "Remove the list containing the given pointer to triangle.", py::arg("thePtr"), py::arg(""));
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentNode.hxx
	py::class_<Poly_CoherentNode, std::unique_ptr<Poly_CoherentNode, Deleter<Poly_CoherentNode>>, gp_XYZ> cls_Poly_CoherentNode(mod, "Poly_CoherentNode", "Node of coherent triangulation. Contains: Coordinates of a 3D point defining the node location 2D point coordinates List of triangles that use this Node Integer index, normally the index of the node in the original triangulation");
	cls_Poly_CoherentNode.def(py::init<>());
	cls_Poly_CoherentNode.def(py::init<const gp_XYZ &>(), py::arg("thePnt"));
	cls_Poly_CoherentNode.def("SetUV", (void (Poly_CoherentNode::*)(const Standard_Real, const Standard_Real)) &Poly_CoherentNode::SetUV, "Set the UV coordinates of the Node.", py::arg("theU"), py::arg("theV"));
	cls_Poly_CoherentNode.def("GetU", (Standard_Real (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::GetU, "Get U coordinate of the Node.");
	cls_Poly_CoherentNode.def("GetV", (Standard_Real (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::GetV, "Get V coordinate of the Node.");
	cls_Poly_CoherentNode.def("SetNormal", (void (Poly_CoherentNode::*)(const gp_XYZ &)) &Poly_CoherentNode::SetNormal, "Define the normal vector in the Node.", py::arg("theVector"));
	cls_Poly_CoherentNode.def("HasNormal", (Standard_Boolean (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::HasNormal, "Query if the Node contains a normal vector.");
	cls_Poly_CoherentNode.def("GetNormal", (gp_XYZ (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::GetNormal, "Get the stored normal in the node.");
	cls_Poly_CoherentNode.def("SetIndex", (void (Poly_CoherentNode::*)(const Standard_Integer)) &Poly_CoherentNode::SetIndex, "Set the value of node Index.", py::arg("theIndex"));
	cls_Poly_CoherentNode.def("GetIndex", (Standard_Integer (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::GetIndex, "Get the value of node Index.");
	cls_Poly_CoherentNode.def("IsFreeNode", (Standard_Boolean (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::IsFreeNode, "Check if this is a free node, i.e., a node without a single incident triangle.");
	cls_Poly_CoherentNode.def("Clear", (void (Poly_CoherentNode::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::Clear, "Reset the Node to void.", py::arg(""));
	cls_Poly_CoherentNode.def("AddTriangle", (void (Poly_CoherentNode::*)(const Poly_CoherentTriangle &, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::AddTriangle, "Connect a triangle to this Node.", py::arg("theTri"), py::arg("theA"));
	cls_Poly_CoherentNode.def("RemoveTriangle", (Standard_Boolean (Poly_CoherentNode::*)(const Poly_CoherentTriangle &, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentNode::RemoveTriangle, "Disconnect a triangle from this Node.", py::arg("theTri"), py::arg("theA"));
	cls_Poly_CoherentNode.def("TriangleIterator", (Poly_CoherentTriPtr::Iterator (Poly_CoherentNode::*)() const ) &Poly_CoherentNode::TriangleIterator, "Create an iterator of incident triangles.");
	// FIXME cls_Poly_CoherentNode.def("Dump", (void (Poly_CoherentNode::*)(Standard_OStream &) const ) &Poly_CoherentNode::Dump, "None", py::arg("theStream"));

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangle.hxx
	py::class_<Poly_CoherentTrianguation, std::unique_ptr<Poly_CoherentTrianguation, Deleter<Poly_CoherentTrianguation>>> cls_Poly_CoherentTrianguation(mod, "Poly_CoherentTrianguation", "None");
	cls_Poly_CoherentTrianguation.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<Poly_Array1OfTriangle, std::unique_ptr<Poly_Array1OfTriangle, Deleter<Poly_Array1OfTriangle>>> cls_Poly_Array1OfTriangle(mod, "Poly_Array1OfTriangle", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_Poly_Array1OfTriangle.def(py::init<>());
	cls_Poly_Array1OfTriangle.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Poly_Array1OfTriangle.def(py::init([] (const Poly_Array1OfTriangle &other) {return new Poly_Array1OfTriangle(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_Poly_Array1OfTriangle.def(py::init<Poly_Array1OfTriangle &&>(), py::arg("theOther"));
	cls_Poly_Array1OfTriangle.def(py::init<const Poly_Triangle &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_Poly_Array1OfTriangle.def("begin", (Poly_Array1OfTriangle::iterator (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::begin, "Returns an iterator pointing to the first element in the array.");
	cls_Poly_Array1OfTriangle.def("end", (Poly_Array1OfTriangle::iterator (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_Poly_Array1OfTriangle.def("cbegin", (Poly_Array1OfTriangle::const_iterator (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_Poly_Array1OfTriangle.def("cend", (Poly_Array1OfTriangle::const_iterator (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_Poly_Array1OfTriangle.def("Init", (void (Poly_Array1OfTriangle::*)(const Poly_Triangle &)) &Poly_Array1OfTriangle::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_Poly_Array1OfTriangle.def("Size", (Standard_Integer (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::Size, "Size query");
	cls_Poly_Array1OfTriangle.def("Length", (Standard_Integer (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::Length, "Length query (the same)");
	cls_Poly_Array1OfTriangle.def("IsEmpty", (Standard_Boolean (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::IsEmpty, "Return TRUE if array has zero length.");
	cls_Poly_Array1OfTriangle.def("Lower", (Standard_Integer (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::Lower, "Lower bound");
	cls_Poly_Array1OfTriangle.def("Upper", (Standard_Integer (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::Upper, "Upper bound");
	cls_Poly_Array1OfTriangle.def("IsDeletable", (Standard_Boolean (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::IsDeletable, "myDeletable flag");
	cls_Poly_Array1OfTriangle.def("IsAllocated", (Standard_Boolean (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_Poly_Array1OfTriangle.def("Assign", (Poly_Array1OfTriangle & (Poly_Array1OfTriangle::*)(const Poly_Array1OfTriangle &)) &Poly_Array1OfTriangle::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_Poly_Array1OfTriangle.def("Move", (Poly_Array1OfTriangle & (Poly_Array1OfTriangle::*)(Poly_Array1OfTriangle &&)) &Poly_Array1OfTriangle::Move, "Move assignment", py::arg("theOther"));
	cls_Poly_Array1OfTriangle.def("assign", (Poly_Array1OfTriangle & (Poly_Array1OfTriangle::*)(const Poly_Array1OfTriangle &)) &Poly_Array1OfTriangle::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_Poly_Array1OfTriangle.def("assign", (Poly_Array1OfTriangle & (Poly_Array1OfTriangle::*)(Poly_Array1OfTriangle &&)) &Poly_Array1OfTriangle::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_Poly_Array1OfTriangle.def("First", (const Poly_Triangle & (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::First, "Returns first element");
	cls_Poly_Array1OfTriangle.def("ChangeFirst", (Poly_Triangle & (Poly_Array1OfTriangle::*)()) &Poly_Array1OfTriangle::ChangeFirst, "Returns first element");
	cls_Poly_Array1OfTriangle.def("Last", (const Poly_Triangle & (Poly_Array1OfTriangle::*)() const ) &Poly_Array1OfTriangle::Last, "Returns last element");
	cls_Poly_Array1OfTriangle.def("ChangeLast", (Poly_Triangle & (Poly_Array1OfTriangle::*)()) &Poly_Array1OfTriangle::ChangeLast, "Returns last element");
	cls_Poly_Array1OfTriangle.def("Value", (const Poly_Triangle & (Poly_Array1OfTriangle::*)(const Standard_Integer) const ) &Poly_Array1OfTriangle::Value, "Constant value access", py::arg("theIndex"));
	cls_Poly_Array1OfTriangle.def("__call__", (const Poly_Triangle & (Poly_Array1OfTriangle::*)(const Standard_Integer) const ) &Poly_Array1OfTriangle::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_Poly_Array1OfTriangle.def("ChangeValue", (Poly_Triangle & (Poly_Array1OfTriangle::*)(const Standard_Integer)) &Poly_Array1OfTriangle::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_Poly_Array1OfTriangle.def("__call__", (Poly_Triangle & (Poly_Array1OfTriangle::*)(const Standard_Integer)) &Poly_Array1OfTriangle::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_Poly_Array1OfTriangle.def("SetValue", (void (Poly_Array1OfTriangle::*)(const Standard_Integer, const Poly_Triangle &)) &Poly_Array1OfTriangle::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_Poly_Array1OfTriangle.def("Resize", (void (Poly_Array1OfTriangle::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Poly_Array1OfTriangle::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_Poly_Array1OfTriangle.def("__iter__", [](const Poly_Array1OfTriangle &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// Callback for Poly_MakeLoops.
	class PyCallback_Poly_MakeLoops : public Poly_MakeLoops {
	public:
		using Poly_MakeLoops::Poly_MakeLoops;

		Standard_Integer chooseLeftWay(const Standard_Integer theNode, const Standard_Integer theSegIndex, const NCollection_List<Standard_Integer> & theLstIndS) const  override { PYBIND11_OVERLOAD_PURE(Standard_Integer, Poly_MakeLoops, chooseLeftWay, theNode, theSegIndex, theLstIndS); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_MakeLoops.hxx
	py::class_<Poly_MakeLoops, std::unique_ptr<Poly_MakeLoops, Deleter<Poly_MakeLoops>>, PyCallback_Poly_MakeLoops> cls_Poly_MakeLoops(mod, "Poly_MakeLoops", "Make loops from a set of connected links. A link is represented by a pair of integer indices of nodes.");
	cls_Poly_MakeLoops.def(py::init<const Poly_MakeLoops::Helper *>(), py::arg("theHelper"));
	cls_Poly_MakeLoops.def(py::init<const Poly_MakeLoops::Helper *, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theHelper"), py::arg("theAlloc"));
	cls_Poly_MakeLoops.def("Reset", [](Poly_MakeLoops &self, const Poly_MakeLoops::Helper * a0) -> void { return self.Reset(a0); }, py::arg("theHelper"));
	cls_Poly_MakeLoops.def("Reset", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Helper *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_MakeLoops::Reset, "It is to reset the algorithm to the initial state.", py::arg("theHelper"), py::arg("theAlloc"));
	cls_Poly_MakeLoops.def("AddLink", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &)) &Poly_MakeLoops::AddLink, "Adds a link to the set. theOrient defines which orientations of the link are allowed.", py::arg("theLink"));
	cls_Poly_MakeLoops.def("ReplaceLink", (void (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &, const Poly_MakeLoops::Link &)) &Poly_MakeLoops::ReplaceLink, "Replace one link with another (e.g. to change order of nodes)", py::arg("theLink"), py::arg("theNewLink"));
	cls_Poly_MakeLoops.def("SetLinkOrientation", (Poly_MakeLoops::LinkFlag (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &, const Poly_MakeLoops::LinkFlag)) &Poly_MakeLoops::SetLinkOrientation, "Set a new value of orientation of a link already added earlier. It can be used with LF_None to exclude the link from consideration. Returns the old value of orienation.", py::arg("theLink"), py::arg("theOrient"));
	cls_Poly_MakeLoops.def("FindLink", (Poly_MakeLoops::Link (Poly_MakeLoops::*)(const Poly_MakeLoops::Link &) const ) &Poly_MakeLoops::FindLink, "Find the link stored in algo by value", py::arg("theLink"));
	cls_Poly_MakeLoops.def("Perform", (Standard_Integer (Poly_MakeLoops::*)()) &Poly_MakeLoops::Perform, "Does the work. Returns the collection of result codes");
	cls_Poly_MakeLoops.def("GetNbLoops", (Standard_Integer (Poly_MakeLoops::*)() const ) &Poly_MakeLoops::GetNbLoops, "Returns the number of loops in the result");
	cls_Poly_MakeLoops.def("GetLoop", (const Poly_MakeLoops::Loop & (Poly_MakeLoops::*)(Standard_Integer) const ) &Poly_MakeLoops::GetLoop, "Returns the loop of the given index", py::arg("theIndex"));
	cls_Poly_MakeLoops.def("GetNbHanging", (Standard_Integer (Poly_MakeLoops::*)() const ) &Poly_MakeLoops::GetNbHanging, "Returns the number of detected hanging chains");
	cls_Poly_MakeLoops.def("GetHangingLinks", (void (Poly_MakeLoops::*)(Poly_MakeLoops::ListOfLink &) const ) &Poly_MakeLoops::GetHangingLinks, "Fills in the list of hanging links", py::arg("theLinks"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_MakeLoops.hxx
	py::class_<Poly_MakeLoops3D, std::unique_ptr<Poly_MakeLoops3D, Deleter<Poly_MakeLoops3D>>, Poly_MakeLoops> cls_Poly_MakeLoops3D(mod, "Poly_MakeLoops3D", "None");
	cls_Poly_MakeLoops3D.def(py::init<const Poly_MakeLoops3D::Helper *, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theHelper"), py::arg("theAlloc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_MakeLoops.hxx
	py::class_<Poly_MakeLoops2D, std::unique_ptr<Poly_MakeLoops2D, Deleter<Poly_MakeLoops2D>>, Poly_MakeLoops> cls_Poly_MakeLoops2D(mod, "Poly_MakeLoops2D", "None");
	cls_Poly_MakeLoops2D.def(py::init<const Standard_Boolean, const Poly_MakeLoops2D::Helper *, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theLeftWay"), py::arg("theHelper"), py::arg("theAlloc"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_HArray1OfTriangle.hxx
	py::class_<Poly_HArray1OfTriangle, opencascade::handle<Poly_HArray1OfTriangle>, Poly_Array1OfTriangle, Standard_Transient> cls_Poly_HArray1OfTriangle(mod, "Poly_HArray1OfTriangle", "None");
	cls_Poly_HArray1OfTriangle.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_Poly_HArray1OfTriangle.def(py::init<const Standard_Integer, const Standard_Integer, const Poly_Array1OfTriangle::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_Poly_HArray1OfTriangle.def(py::init<const Poly_Array1OfTriangle &>(), py::arg("theOther"));
	cls_Poly_HArray1OfTriangle.def("Array1", (const Poly_Array1OfTriangle & (Poly_HArray1OfTriangle::*)() const ) &Poly_HArray1OfTriangle::Array1, "None");
	cls_Poly_HArray1OfTriangle.def("ChangeArray1", (Poly_Array1OfTriangle & (Poly_HArray1OfTriangle::*)()) &Poly_HArray1OfTriangle::ChangeArray1, "None");
	cls_Poly_HArray1OfTriangle.def_static("get_type_name_", (const char * (*)()) &Poly_HArray1OfTriangle::get_type_name, "None");
	cls_Poly_HArray1OfTriangle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_HArray1OfTriangle::get_type_descriptor, "None");
	cls_Poly_HArray1OfTriangle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_HArray1OfTriangle::*)() const ) &Poly_HArray1OfTriangle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<Poly_ListOfTriangulation, std::unique_ptr<Poly_ListOfTriangulation, Deleter<Poly_ListOfTriangulation>>, NCollection_BaseList> cls_Poly_ListOfTriangulation(mod, "Poly_ListOfTriangulation", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_Poly_ListOfTriangulation.def(py::init<>());
	cls_Poly_ListOfTriangulation.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Poly_ListOfTriangulation.def(py::init([] (const Poly_ListOfTriangulation &other) {return new Poly_ListOfTriangulation(other);}), "Copy constructor", py::arg("other"));
	cls_Poly_ListOfTriangulation.def("begin", (Poly_ListOfTriangulation::iterator (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::begin, "Returns an iterator pointing to the first element in the list.");
	cls_Poly_ListOfTriangulation.def("end", (Poly_ListOfTriangulation::iterator (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_Poly_ListOfTriangulation.def("cbegin", (Poly_ListOfTriangulation::const_iterator (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_Poly_ListOfTriangulation.def("cend", (Poly_ListOfTriangulation::const_iterator (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_Poly_ListOfTriangulation.def("Size", (Standard_Integer (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::Size, "Size - Number of items");
	cls_Poly_ListOfTriangulation.def("Assign", (Poly_ListOfTriangulation & (Poly_ListOfTriangulation::*)(const Poly_ListOfTriangulation &)) &Poly_ListOfTriangulation::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_Poly_ListOfTriangulation.def("assign", (Poly_ListOfTriangulation & (Poly_ListOfTriangulation::*)(const Poly_ListOfTriangulation &)) &Poly_ListOfTriangulation::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Poly_ListOfTriangulation.def("Clear", [](Poly_ListOfTriangulation &self) -> void { return self.Clear(); });
	cls_Poly_ListOfTriangulation.def("Clear", (void (Poly_ListOfTriangulation::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_ListOfTriangulation::Clear, "Clear this list", py::arg("theAllocator"));
	cls_Poly_ListOfTriangulation.def("First", (const opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::First, "First item");
	cls_Poly_ListOfTriangulation.def("First", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)()) &Poly_ListOfTriangulation::First, "First item (non-const)");
	cls_Poly_ListOfTriangulation.def("Last", (const opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)() const ) &Poly_ListOfTriangulation::Last, "Last item");
	cls_Poly_ListOfTriangulation.def("Last", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)()) &Poly_ListOfTriangulation::Last, "Last item (non-const)");
	cls_Poly_ListOfTriangulation.def("Append", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)(const opencascade::handle<Poly_Triangulation> &)) &Poly_ListOfTriangulation::Append, "Append one item at the end", py::arg("theItem"));
	cls_Poly_ListOfTriangulation.def("Append", (void (Poly_ListOfTriangulation::*)(const opencascade::handle<Poly_Triangulation> &, Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("Append", (void (Poly_ListOfTriangulation::*)(Poly_ListOfTriangulation &)) &Poly_ListOfTriangulation::Append, "Append another list at the end", py::arg("theOther"));
	cls_Poly_ListOfTriangulation.def("Prepend", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)(const opencascade::handle<Poly_Triangulation> &)) &Poly_ListOfTriangulation::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_Poly_ListOfTriangulation.def("Prepend", (void (Poly_ListOfTriangulation::*)(Poly_ListOfTriangulation &)) &Poly_ListOfTriangulation::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_Poly_ListOfTriangulation.def("RemoveFirst", (void (Poly_ListOfTriangulation::*)()) &Poly_ListOfTriangulation::RemoveFirst, "RemoveFirst item");
	cls_Poly_ListOfTriangulation.def("Remove", (void (Poly_ListOfTriangulation::*)(Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("InsertBefore", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)(const opencascade::handle<Poly_Triangulation> &, Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("InsertBefore", (void (Poly_ListOfTriangulation::*)(Poly_ListOfTriangulation &, Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("InsertAfter", (opencascade::handle<Poly_Triangulation> & (Poly_ListOfTriangulation::*)(const opencascade::handle<Poly_Triangulation> &, Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("InsertAfter", (void (Poly_ListOfTriangulation::*)(Poly_ListOfTriangulation &, Poly_ListOfTriangulation::Iterator &)) &Poly_ListOfTriangulation::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_Poly_ListOfTriangulation.def("Reverse", (void (Poly_ListOfTriangulation::*)()) &Poly_ListOfTriangulation::Reverse, "Reverse the list");
	cls_Poly_ListOfTriangulation.def("__iter__", [](const Poly_ListOfTriangulation &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangulation.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangulation.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\Poly_CoherentTriangulation.hxx

}
