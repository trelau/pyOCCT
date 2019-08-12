/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <BRepFilletAPI_LocalOperation.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopTools_ListOfShape.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <ChFi3d_ChBuilder.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>

void bind_BRepFilletAPI_MakeChamfer(py::module &mod){

py::class_<BRepFilletAPI_MakeChamfer, std::unique_ptr<BRepFilletAPI_MakeChamfer, Deleter<BRepFilletAPI_MakeChamfer>>, BRepFilletAPI_LocalOperation> cls_BRepFilletAPI_MakeChamfer(mod, "BRepFilletAPI_MakeChamfer", "Describes functions to build chamfers on edges of a shell or solid. Chamfered Edge of a Shell or Solid A MakeChamfer object provides a framework for: - initializing the construction algorithm with a given shape, - acquiring the data characterizing the chamfers, - building the chamfers and constructing the resulting shape, and - consulting the result.");

// Constructors
cls_BRepFilletAPI_MakeChamfer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepFilletAPI_MakeChamfer.def_static("operator new_", (void * (*)(size_t)) &BRepFilletAPI_MakeChamfer::operator new, "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeChamfer.def_static("operator delete_", (void (*)(void *)) &BRepFilletAPI_MakeChamfer::operator delete, "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeChamfer.def_static("operator new[]_", (void * (*)(size_t)) &BRepFilletAPI_MakeChamfer::operator new[], "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeChamfer.def_static("operator delete[]_", (void (*)(void *)) &BRepFilletAPI_MakeChamfer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeChamfer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFilletAPI_MakeChamfer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFilletAPI_MakeChamfer.def_static("operator delete_", (void (*)(void *, void *)) &BRepFilletAPI_MakeChamfer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFilletAPI_MakeChamfer.def("Add", (void (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeChamfer::Add, "Adds edge E to the table of edges used by this algorithm to build chamfers, where the parameters of the chamfer must be set after the", py::arg("E"));
cls_BRepFilletAPI_MakeChamfer.def("Add", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::Add, "Adds edge E to the table of edges used by this algorithm to build chamfers, where the parameters of the chamfer are given by the two distances Dis1 and Dis2; the face F identifies the side where Dis1 is measured. The Add function results in a contour being built by propagation from the edge E (i.e. the contour contains at least this edge). This contour is composed of edges of the shape which are tangential to one another and which delimit two series of tangential faces, with one series of faces being located on either side of the contour. Warning Nothing is done if edge E or the face F does not belong to the initial shape.", py::arg("Dis"), py::arg("E"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("SetDist", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::SetDist, "Sets the distances Dis1 and Dis2 which give the parameters of the chamfer along the contour of index IC generated using the Add function in the internal data structure of this algorithm. The face F identifies the side where Dis1 is measured. Warning Nothing is done if either the edge E or the face F does not belong to the initial shape.", py::arg("Dis"), py::arg("IC"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("GetDist", [](BRepFilletAPI_MakeChamfer &self, const Standard_Integer IC, Standard_Real & Dis){ self.GetDist(IC, Dis); return Dis; }, "None", py::arg("IC"), py::arg("Dis"));
cls_BRepFilletAPI_MakeChamfer.def("Add", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::Add, "Adds a fillet contour in the builder (builds a contour of tangent edges to <E> and sets the two distances <Dis1> and <Dis2> ( parameters of the chamfer ) ).", py::arg("Dis1"), py::arg("Dis2"), py::arg("E"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("SetDists", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::SetDists, "Sets the distances Dis1 and Dis2 which give the parameters of the chamfer along the contour of index IC generated using the Add function in the internal data structure of this algorithm. The face F identifies the side where Dis1 is measured. Warning Nothing is done if either the edge E or the face F does not belong to the initial shape.", py::arg("Dis1"), py::arg("Dis2"), py::arg("IC"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("Dists", [](BRepFilletAPI_MakeChamfer &self, const Standard_Integer IC, Standard_Real & Dis1, Standard_Real & Dis2){ self.Dists(IC, Dis1, Dis2); return std::tuple<Standard_Real &, Standard_Real &>(Dis1, Dis2); }, "Returns the distances Dis1 and Dis2 which give the parameters of the chamfer along the contour of index IC in the internal data structure of this algorithm. Warning -1. is returned if IC is outside the bounds of the table of contours.", py::arg("IC"), py::arg("Dis1"), py::arg("Dis2"));
cls_BRepFilletAPI_MakeChamfer.def("AddDA", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::AddDA, "Adds a fillet contour in the builder (builds a contour of tangent edges to <E> and sets the distance <Dis1> and angle <Angle> ( parameters of the chamfer ) ).", py::arg("Dis"), py::arg("Angle"), py::arg("E"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("SetDistAngle", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const TopoDS_Face &)) &BRepFilletAPI_MakeChamfer::SetDistAngle, "set the distance <Dis> and <Angle> of the fillet contour of index <IC> in the DS with <Dis> on <F>. if the face <F> is not one of common faces of an edge of the contour <IC>", py::arg("Dis"), py::arg("Angle"), py::arg("IC"), py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("GetDistAngle", [](BRepFilletAPI_MakeChamfer &self, const Standard_Integer IC, Standard_Real & Dis, Standard_Real & Angle, Standard_Boolean & DisOnFace1){ self.GetDistAngle(IC, Dis, Angle, DisOnFace1); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(Dis, Angle, DisOnFace1); }, "gives the distances <Dis> and <Angle> of the fillet contour of index <IC> in the DS", py::arg("IC"), py::arg("Dis"), py::arg("Angle"), py::arg("DisOnFace1"));
cls_BRepFilletAPI_MakeChamfer.def("IsSymetric", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::IsSymetric, "return True if chamfer symetric false else.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("IsTwoDistances", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::IsTwoDistances, "return True if chamfer is made with two distances false else.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("IsDistanceAngle", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::IsDistanceAngle, "return True if chamfer is made with distance and angle false else.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("ResetContour", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer)) &BRepFilletAPI_MakeChamfer::ResetContour, "Erases the chamfer parameters on the contour of index IC in the internal data structure of this algorithm. Use the SetDists function to reset this data. Warning Nothing is done if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("NbContours", (Standard_Integer (BRepFilletAPI_MakeChamfer::*)() const) &BRepFilletAPI_MakeChamfer::NbContours, "Returns the number of contours generated using the Add function in the internal data structure of this algorithm.");
cls_BRepFilletAPI_MakeChamfer.def("Contour", (Standard_Integer (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeChamfer::Contour, "Returns the index of the contour in the internal data structure of this algorithm, which contains the edge E of the shape. This function returns 0 if the edge E does not belong to any contour. Warning This index can change if a contour is removed from the internal data structure of this algorithm using the function Remove.", py::arg("E"));
cls_BRepFilletAPI_MakeChamfer.def("NbEdges", (Standard_Integer (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::NbEdges, "Returns the number of edges in the contour of index I in the internal data structure of this algorithm. Warning Returns 0 if I is outside the bounds of the table of contours.", py::arg("I"));
cls_BRepFilletAPI_MakeChamfer.def("Edge", (const TopoDS_Edge & (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::Edge, "Returns the edge of index J in the contour of index I in the internal data structure of this algorithm. Warning Returns a null shape if: - I is outside the bounds of the table of contours, or - J is outside the bounds of the table of edges of the contour of index I.", py::arg("I"), py::arg("J"));
cls_BRepFilletAPI_MakeChamfer.def("Remove", (void (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeChamfer::Remove, "Removes the contour in the internal data structure of this algorithm which contains the edge E of the shape. Warning Nothing is done if the edge E does not belong to the contour in the internal data structure of this algorithm.", py::arg("E"));
cls_BRepFilletAPI_MakeChamfer.def("Length", (Standard_Real (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::Length, "Returns the length of the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("FirstVertex", (TopoDS_Vertex (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::FirstVertex, "Returns the first vertex of the contour of index IC in the internal data structure of this algorithm. Warning Returns a null shape if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("LastVertex", (TopoDS_Vertex (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::LastVertex, "Returns the last vertex of the contour of index IC in the internal data structure of this algorithm. Warning Returns a null shape if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("Abscissa", (Standard_Real (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_MakeChamfer::Abscissa, "Returns the curvilinear abscissa of the vertex V on the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if: - IC is outside the bounds of the table of contours, or - V is not on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_MakeChamfer.def("RelativeAbscissa", (Standard_Real (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_MakeChamfer::RelativeAbscissa, "Returns the relative curvilinear abscissa (i.e. between 0 and 1) of the vertex V on the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if: - IC is outside the bounds of the table of contours, or - V is not on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_MakeChamfer.def("ClosedAndTangent", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::ClosedAndTangent, "eturns true if the contour of index IC in the internal data structure of this algorithm is closed and tangential at the point of closure. Warning Returns false if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("Closed", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::Closed, "Returns true if the contour of index IC in the internal data structure of this algorithm is closed. Warning Returns false if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("Build", (void (BRepFilletAPI_MakeChamfer::*)()) &BRepFilletAPI_MakeChamfer::Build, "Builds the chamfers on all the contours in the internal data structure of this algorithm and constructs the resulting shape. Use the function IsDone to verify that the chamfered shape is built. Use the function Shape to retrieve the chamfered shape. Warning The construction of chamfers implements highly complex construction algorithms. Consequently, there may be instances where the algorithm fails, for example if the data defining the parameters of the chamfer is not compatible with the geometry of the initial shape. There is no initial analysis of errors and these only become evident at the construction stage. Additionally, in the current software release, the following cases are not handled: - the end point of the contour is the point of intersection of 4 or more edges of the shape, or - the intersection of the chamfer with a face which limits the contour is not fully contained in this face.");
cls_BRepFilletAPI_MakeChamfer.def("Reset", (void (BRepFilletAPI_MakeChamfer::*)()) &BRepFilletAPI_MakeChamfer::Reset, "Reinitializes this algorithm, thus canceling the effects of the Build function. This function allows modifications to be made to the contours and chamfer parameters in order to rebuild the shape.");
cls_BRepFilletAPI_MakeChamfer.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (BRepFilletAPI_MakeChamfer::*)() const) &BRepFilletAPI_MakeChamfer::Builder, "Returns the internal filleting algorithm.");
cls_BRepFilletAPI_MakeChamfer.def("Generated", (const TopTools_ListOfShape & (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeChamfer::Generated, "Returns the list of shapes generated from the shape <EorV>.", py::arg("EorV"));
cls_BRepFilletAPI_MakeChamfer.def("Modified", (const TopTools_ListOfShape & (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeChamfer::Modified, "Returns the list of shapes modified from the shape <F>.", py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("IsDeleted", (Standard_Boolean (BRepFilletAPI_MakeChamfer::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeChamfer::IsDeleted, "None", py::arg("F"));
cls_BRepFilletAPI_MakeChamfer.def("Simulate", (void (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer)) &BRepFilletAPI_MakeChamfer::Simulate, "None", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("NbSurf", (Standard_Integer (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::NbSurf, "None", py::arg("IC"));
cls_BRepFilletAPI_MakeChamfer.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (BRepFilletAPI_MakeChamfer::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_MakeChamfer::Sect, "None", py::arg("IC"), py::arg("IS"));

// Enums

}