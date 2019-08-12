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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <ChFi2d_ConstructionError.hxx>
#include <ChFi2d_Builder.hxx>
#include <BRepFilletAPI_MakeFillet2d.hxx>

void bind_BRepFilletAPI_MakeFillet2d(py::module &mod){

py::class_<BRepFilletAPI_MakeFillet2d, std::unique_ptr<BRepFilletAPI_MakeFillet2d, Deleter<BRepFilletAPI_MakeFillet2d>>, BRepBuilderAPI_MakeShape> cls_BRepFilletAPI_MakeFillet2d(mod, "BRepFilletAPI_MakeFillet2d", "Describes functions to build fillets and chamfers on the vertices of a planar face. Fillets and Chamfers on the Vertices of a Planar Face A MakeFillet2d object provides a framework for: - initializing the construction algorithm with a given face, - acquiring the data characterizing the fillets and chamfers, - building the fillets and chamfers, and constructing the resulting shape, and - consulting the result. Warning Only segments of straight lines and arcs of circles are treated. BSplines are not processed.");

// Constructors
cls_BRepFilletAPI_MakeFillet2d.def(py::init<>());
cls_BRepFilletAPI_MakeFillet2d.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator new_", (void * (*)(size_t)) &BRepFilletAPI_MakeFillet2d::operator new, "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator delete_", (void (*)(void *)) &BRepFilletAPI_MakeFillet2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepFilletAPI_MakeFillet2d::operator new[], "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator delete[]_", (void (*)(void *)) &BRepFilletAPI_MakeFillet2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFilletAPI_MakeFillet2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepFilletAPI_MakeFillet2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFilletAPI_MakeFillet2d.def("Init", (void (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Face &)) &BRepFilletAPI_MakeFillet2d::Init, "Initializes this algorithm for constructing fillets or chamfers with the face F. Warning The status of the initialization, as given by the Status function, can be one of the following: - ChFi2d_Ready if the initialization is correct, - ChFi2d_NotPlanar if F is not planar, - ChFi2d_NoFace if F is a null face.", py::arg("F"));
cls_BRepFilletAPI_MakeFillet2d.def("Init", (void (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Face &, const TopoDS_Face &)) &BRepFilletAPI_MakeFillet2d::Init, "This initialize method allow to init the builder from a face <RefFace> and another face <ModFace> which derive from <RefFace>. This is usefull to modify a fillet or a chamfer already created on <ModFace> .", py::arg("RefFace"), py::arg("ModFace"));
cls_BRepFilletAPI_MakeFillet2d.def("AddFillet", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Vertex &, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::AddFillet, "Adds a fillet of radius Radius between the two edges adjacent to the vertex V on the face modified by this algorithm. The two edges do not need to be rectilinear. This function returns the fillet and builds the resulting face. Warning The status of the construction, as given by the Status function, can be one of the following: - ChFi2d_IsDone if the fillet is built, - ChFi2d_ConnexionError if V does not belong to the initial face, - ChFi2d_ComputationError if Radius is too large to build a fillet between the two adjacent edges, - ChFi2d_NotAuthorized - if one of the two edges connected to V is a fillet or chamfer, or - if a curve other than a straight line or an arc of a circle is used as E, E1 or E2. Do not use the returned fillet if the status of the construction is not ChFi2d_IsDone. Exceptions Standard_NegativeValue if Radius is less than or equal to zero.", py::arg("V"), py::arg("Radius"));
cls_BRepFilletAPI_MakeFillet2d.def("ModifyFillet", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::ModifyFillet, "Assigns the radius Radius to the fillet Fillet already built on the face modified by this algorithm. This function returns the new fillet and modifies the existing face. Warning The status of the construction, as given by the Status function, can be one of the following: - ChFi2d_IsDone if the new fillet is built, - ChFi2d_ConnexionError if Fillet does not belong to the existing face, - ChFi2d_ComputationError if Radius is too large to build a fillet between the two adjacent edges. Do not use the returned fillet if the status of the construction is not ChFi2d_IsDone. Exceptions Standard_NegativeValue if Radius is less than or equal to zero.", py::arg("Fillet"), py::arg("Radius"));
cls_BRepFilletAPI_MakeFillet2d.def("RemoveFillet", (TopoDS_Vertex (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet2d::RemoveFillet, "Removes the fillet Fillet already built on the face modified by this algorithm. This function returns the vertex connecting the two adjacent edges of Fillet and modifies the existing face. Warning - The returned vertex is only valid if the Status function returns ChFi2d_IsDone. - A null vertex is returned if the edge Fillet does not belong to the initial face.", py::arg("Fillet"));
cls_BRepFilletAPI_MakeFillet2d.def("AddChamfer", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::AddChamfer, "Adds a chamfer on the face modified by this algorithm between the two adjacent edges E1 and E2, where the extremities of the chamfer are on E1 and E2 at distances D1 and D2 respectively In cases where the edges are not rectilinear, distances are measured using the curvilinear abscissa of the edges and the angle is measured with respect to the tangent at the corresponding point. The angle Ang is given in radians. This function returns the chamfer and builds the resulting face.", py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
cls_BRepFilletAPI_MakeFillet2d.def("AddChamfer", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::AddChamfer, "Adds a chamfer on the face modified by this algorithm between the two edges connected by the vertex V, where E is one of the two edges. The chamfer makes an angle Ang with E and one of its extremities is on E at distance D from V. In cases where the edges are not rectilinear, distances are measured using the curvilinear abscissa of the edges and the angle is measured with respect to the tangent at the corresponding point. The angle Ang is given in radians. This function returns the chamfer and builds the resulting face. Warning The status of the construction, as given by the Status function, can be one of the following: - ChFi2d_IsDone if the chamfer is built, - ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero, - ChFi2d_ConnexionError if: - the edge E, E1 or E2 does not belong to the initial face, or - the edges E1 and E2 are not adjacent, or - the vertex V is not one of the limit points of the edge E, - ChFi2d_ComputationError if the parameters of the chamfer are too large to build a chamfer between the two adjacent edges, - ChFi2d_NotAuthorized if: - the edge E1, E2 or one of the two edges connected to V is a fillet or chamfer, or - a curve other than a straight line or an arc of a circle is used as E, E1 or E2. Do not use the returned chamfer if the status of the construction is not ChFi2d_IsDone.", py::arg("E"), py::arg("V"), py::arg("D"), py::arg("Ang"));
cls_BRepFilletAPI_MakeFillet2d.def("ModifyChamfer", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::ModifyChamfer, "Modifies the chamfer Chamfer on the face modified by this algorithm, where: E1 and E2 are the two adjacent edges on which Chamfer is already built; the extremities of the new chamfer are on E1 and E2 at distances D1 and D2 respectively.", py::arg("Chamfer"), py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
cls_BRepFilletAPI_MakeFillet2d.def("ModifyChamfer", (TopoDS_Edge (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &BRepFilletAPI_MakeFillet2d::ModifyChamfer, "Modifies the chamfer Chamfer on the face modified by this algorithm, where: E is one of the two adjacent edges on which Chamfer is already built; the new chamfer makes an angle Ang with E and one of its extremities is on E at distance D from the vertex on which the chamfer is built. In cases where the edges are not rectilinear, the distances are measured using the curvilinear abscissa of the edges and the angle is measured with respect to the tangent at the corresponding point. The angle Ang is given in radians. This function returns the new chamfer and modifies the existing face. Warning The status of the construction, as given by the Status function, can be one of the following: - ChFi2d_IsDone if the chamfer is built, - ChFi2d_ParametersError if D1, D2, D or Ang is less than or equal to zero, - ChFi2d_ConnexionError if: - the edge E, E1, E2 or Chamfer does not belong to the existing face, or - the edges E1 and E2 are not adjacent, - ChFi2d_ComputationError if the parameters of the chamfer are too large to build a chamfer between the two adjacent edges, - ChFi2d_NotAuthorized if E1 or E2 is a fillet or chamfer. Do not use the returned chamfer if the status of the construction is not ChFi2d_IsDone.", py::arg("Chamfer"), py::arg("E"), py::arg("D"), py::arg("Ang"));
cls_BRepFilletAPI_MakeFillet2d.def("RemoveChamfer", (TopoDS_Vertex (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet2d::RemoveChamfer, "Removes the chamfer Chamfer already built on the face modified by this algorithm. This function returns the vertex connecting the two adjacent edges of Chamfer and modifies the existing face. Warning - The returned vertex is only valid if the Status function returns ChFi2d_IsDone. - A null vertex is returned if the edge Chamfer does not belong to the initial face.", py::arg("Chamfer"));
cls_BRepFilletAPI_MakeFillet2d.def("IsModified", (Standard_Boolean (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeFillet2d::IsModified, "Returns true if the edge E on the face modified by this algorithm is chamfered or filleted. Warning Returns false if E does not belong to the face modified by this algorithm.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet2d.def("FilletEdges", (const TopTools_SequenceOfShape & (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::FilletEdges, "Returns the table of fillets on the face modified by this algorithm.");
cls_BRepFilletAPI_MakeFillet2d.def("NbFillet", (Standard_Integer (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::NbFillet, "Returns the number of fillets on the face modified by this algorithm.");
cls_BRepFilletAPI_MakeFillet2d.def("ChamferEdges", (const TopTools_SequenceOfShape & (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::ChamferEdges, "Returns the table of chamfers on the face modified by this algorithm.");
cls_BRepFilletAPI_MakeFillet2d.def("NbChamfer", (Standard_Integer (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::NbChamfer, "Returns the number of chamfers on the face modified by this algorithm.");
cls_BRepFilletAPI_MakeFillet2d.def("Modified", (const TopTools_ListOfShape & (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeFillet2d::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepFilletAPI_MakeFillet2d.def("NbCurves", (Standard_Integer (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::NbCurves, "returns the number of new curves after the shape creation.");
cls_BRepFilletAPI_MakeFillet2d.def("NewEdges", (const TopTools_ListOfShape & (BRepFilletAPI_MakeFillet2d::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet2d::NewEdges, "Return the Edges created for curve I.", py::arg("I"));
cls_BRepFilletAPI_MakeFillet2d.def("HasDescendant", (Standard_Boolean (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeFillet2d::HasDescendant, "None", py::arg("E"));
cls_BRepFilletAPI_MakeFillet2d.def("DescendantEdge", (const TopoDS_Edge & (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeFillet2d::DescendantEdge, "Returns the chamfered or filleted edge built from the edge E on the face modified by this algorithm. If E has not been modified, this function returns E. Exceptions Standard_NoSuchObject if the edge E does not belong to the initial face.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet2d.def("BasisEdge", (const TopoDS_Edge & (BRepFilletAPI_MakeFillet2d::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeFillet2d::BasisEdge, "Returns the basis edge on the face modified by this algorithm from which the chamfered or filleted edge E is built. If E has not been modified, this function returns E. Warning E is returned if it does not belong to the initial face.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet2d.def("Status", (ChFi2d_ConstructionError (BRepFilletAPI_MakeFillet2d::*)() const) &BRepFilletAPI_MakeFillet2d::Status, "None");
cls_BRepFilletAPI_MakeFillet2d.def("Build", (void (BRepFilletAPI_MakeFillet2d::*)()) &BRepFilletAPI_MakeFillet2d::Build, "Update the result and set the Done flag");

// Enums

}