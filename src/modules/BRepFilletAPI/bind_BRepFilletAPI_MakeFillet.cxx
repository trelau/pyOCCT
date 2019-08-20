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
#include <ChFi3d_FilletShape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopTools_ListOfShape.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <Geom_Surface.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <ChFi3d_FilBuilder.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepFilletAPI_MakeFillet.hxx>

void bind_BRepFilletAPI_MakeFillet(py::module &mod){

py::class_<BRepFilletAPI_MakeFillet, std::unique_ptr<BRepFilletAPI_MakeFillet>, BRepFilletAPI_LocalOperation> cls_BRepFilletAPI_MakeFillet(mod, "BRepFilletAPI_MakeFillet", "Describes functions to build fillets on the broken edges of a shell or solid. A MakeFillet object provides a framework for: - initializing the construction algorithm with a given shape, - acquiring the data characterizing the fillets, - building the fillets and constructing the resulting shape, and - consulting the result.");

// Constructors
cls_BRepFilletAPI_MakeFillet.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepFilletAPI_MakeFillet.def(py::init<const TopoDS_Shape &, const ChFi3d_FilletShape>(), py::arg("S"), py::arg("FShape"));

// Fields

// Methods
// cls_BRepFilletAPI_MakeFillet.def_static("operator new_", (void * (*)(size_t)) &BRepFilletAPI_MakeFillet::operator new, "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeFillet.def_static("operator delete_", (void (*)(void *)) &BRepFilletAPI_MakeFillet::operator delete, "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet.def_static("operator new[]_", (void * (*)(size_t)) &BRepFilletAPI_MakeFillet::operator new[], "None", py::arg("theSize"));
// cls_BRepFilletAPI_MakeFillet.def_static("operator delete[]_", (void (*)(void *)) &BRepFilletAPI_MakeFillet::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFilletAPI_MakeFillet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFilletAPI_MakeFillet.def_static("operator delete_", (void (*)(void *, void *)) &BRepFilletAPI_MakeFillet::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFilletAPI_MakeFillet.def("SetParams", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFilletAPI_MakeFillet::SetParams, "None", py::arg("Tang"), py::arg("Tesp"), py::arg("T2d"), py::arg("TApp3d"), py::arg("TolApp2d"), py::arg("Fleche"));
cls_BRepFilletAPI_MakeFillet.def("SetContinuity", (void (BRepFilletAPI_MakeFillet::*)(const GeomAbs_Shape, const Standard_Real)) &BRepFilletAPI_MakeFillet::SetContinuity, "Changes the parameters of continiuity InternalContinuity to produce fillet'surfaces with an continuity Ci (i=0,1 or 2). By defaultInternalContinuity = GeomAbs_C1. AngularTolerance is the G1 tolerance between fillet and support'faces.", py::arg("InternalContinuity"), py::arg("AngularTolerance"));
cls_BRepFilletAPI_MakeFillet.def("Add", (void (BRepFilletAPI_MakeFillet::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Add, "Adds a fillet contour in the builder (builds a contour of tangent edges). The Radius must be set after.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Add", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Add, "Adds a fillet description in the builder - builds a contour of tangent edges, - sets the radius.", py::arg("Radius"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Add", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Real, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Add, "Adds a fillet description in the builder - builds a contour of tangent edges, - sets a linear radius evolution law between the first and last vertex of the spine.", py::arg("R1"), py::arg("R2"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Add", (void (BRepFilletAPI_MakeFillet::*)(const opencascade::handle<Law_Function> &, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Add, "Adds a fillet description in the builder - builds a contour of tangent edges, - sest the radius evolution law.", py::arg("L"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Add", (void (BRepFilletAPI_MakeFillet::*)(const TColgp_Array1OfPnt2d &, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Add, "Adds a fillet description in the builder - builds a contour of tangent edges, - sets the radius evolution law interpolating the values given in the array UandR :", py::arg("UandR"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &BRepFilletAPI_MakeFillet::SetRadius, "Sets the parameters of the fillet along the contour of index IC generated using the Add function in the internal data structure of this algorithm, where Radius is the radius of the fillet.", py::arg("Radius"), py::arg("IC"), py::arg("IinC"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &BRepFilletAPI_MakeFillet::SetRadius, "Sets the parameters of the fillet along the contour of index IC generated using the Add function in the internal data structure of this algorithm, where the radius of the fillet evolves according to a linear evolution law defined from R1 to R2, between the first and last vertices of the contour of index IC.", py::arg("R1"), py::arg("R2"), py::arg("IC"), py::arg("IinC"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const opencascade::handle<Law_Function> &, const Standard_Integer, const Standard_Integer)) &BRepFilletAPI_MakeFillet::SetRadius, "Sets the parameters of the fillet along the contour of index IC generated using the Add function in the internal data structure of this algorithm, where the radius of the fillet evolves according to the evolution law L, between the first and last vertices of the contour of index IC.", py::arg("L"), py::arg("IC"), py::arg("IinC"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const TColgp_Array1OfPnt2d &, const Standard_Integer, const Standard_Integer)) &BRepFilletAPI_MakeFillet::SetRadius, "Sets the parameters of the fillet along the contour of index IC generated using the Add function in the internal data structure of this algorithm, where the radius of the fillet evolves according to the evolution law which interpolates the set of parameter and radius pairs given in the array UandR as follows: - the X coordinate of a point in UandR defines a relative parameter on the contour (i.e. a parameter between 0 and 1), - the Y coordinate of a point in UandR gives the corresponding value of the radius, and the radius evolves between the first and last vertices of the contour of index IC.", py::arg("UandR"), py::arg("IC"), py::arg("IinC"));
cls_BRepFilletAPI_MakeFillet.def("ResetContour", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet::ResetContour, "Erases the radius information on the contour of index IC in the internal data structure of this algorithm. Use the SetRadius function to reset this data. Warning Nothing is done if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("IsConstant", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet::IsConstant, "Returns true if the radius of the fillet along the contour of index IC in the internal data structure of this algorithm is constant, Warning False is returned if IC is outside the bounds of the table of contours or if E does not belong to the contour of index IC.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("Radius", (Standard_Real (BRepFilletAPI_MakeFillet::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet::Radius, "Returns the radius of the fillet along the contour of index IC in the internal data structure of this algorithm Warning - Use this function only if the radius is constant. - -1. is returned if IC is outside the bounds of the table of contours or if E does not belong to the contour of index IC.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("IsConstant", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::IsConstant, "Returns true if the radius of the fillet along the edge E of the contour of index IC in the internal data structure of this algorithm is constant. Warning False is returned if IC is outside the bounds of the table of contours or if E does not belong to the contour of index IC.", py::arg("IC"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Radius", (Standard_Real (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Radius, "Returns the radius of the fillet along the edge E of the contour of index IC in the internal data structure of this algorithm. Warning - Use this function only if the radius is constant. - -1 is returned if IC is outside the bounds of the table of contours or if E does not belong to the contour of index IC.", py::arg("IC"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Integer, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::SetRadius, "Assigns Radius as the radius of the fillet on the edge E", py::arg("Radius"), py::arg("IC"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("SetRadius", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Real, const Standard_Integer, const TopoDS_Vertex &)) &BRepFilletAPI_MakeFillet::SetRadius, "None", py::arg("Radius"), py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_MakeFillet.def("GetBounds", [](BRepFilletAPI_MakeFillet &self, const Standard_Integer IC, const TopoDS_Edge & E, Standard_Real & F, Standard_Real & L){ Standard_Boolean rv = self.GetBounds(IC, E, F, L); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, L); }, "None", py::arg("IC"), py::arg("E"), py::arg("F"), py::arg("L"));
cls_BRepFilletAPI_MakeFillet.def("GetLaw", (opencascade::handle<Law_Function> (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::GetLaw, "None", py::arg("IC"), py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("SetLaw", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Edge &, const opencascade::handle<Law_Function> &)) &BRepFilletAPI_MakeFillet::SetLaw, "None", py::arg("IC"), py::arg("E"), py::arg("L"));
cls_BRepFilletAPI_MakeFillet.def("SetFilletShape", (void (BRepFilletAPI_MakeFillet::*)(const ChFi3d_FilletShape)) &BRepFilletAPI_MakeFillet::SetFilletShape, "Assigns FShape as the type of fillet shape built by this algorithm.", py::arg("FShape"));
cls_BRepFilletAPI_MakeFillet.def("GetFilletShape", (ChFi3d_FilletShape (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::GetFilletShape, "Returns the type of fillet shape built by this algorithm.");
cls_BRepFilletAPI_MakeFillet.def("NbContours", (Standard_Integer (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::NbContours, "Returns the number of contours generated using the Add function in the internal data structure of this algorithm.");
cls_BRepFilletAPI_MakeFillet.def("Contour", (Standard_Integer (BRepFilletAPI_MakeFillet::*)(const TopoDS_Edge &) const) &BRepFilletAPI_MakeFillet::Contour, "Returns the index of the contour in the internal data structure of this algorithm which contains the edge E of the shape. This function returns 0 if the edge E does not belong to any contour. Warning This index can change if a contour is removed from the internal data structure of this algorithm using the function Remove.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("NbEdges", (Standard_Integer (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::NbEdges, "Returns the number of edges in the contour of index I in the internal data structure of this algorithm. Warning Returns 0 if I is outside the bounds of the table of contours.", py::arg("I"));
cls_BRepFilletAPI_MakeFillet.def("Edge", (const TopoDS_Edge & (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_MakeFillet::Edge, "Returns the edge of index J in the contour of index I in the internal data structure of this algorithm. Warning Returns a null shape if: - I is outside the bounds of the table of contours, or - J is outside the bounds of the table of edges of the index I contour.", py::arg("I"), py::arg("J"));
cls_BRepFilletAPI_MakeFillet.def("Remove", (void (BRepFilletAPI_MakeFillet::*)(const TopoDS_Edge &)) &BRepFilletAPI_MakeFillet::Remove, "Removes the contour in the internal data structure of this algorithm which contains the edge E of the shape. Warning Nothing is done if the edge E does not belong to the contour in the internal data structure of this algorithm.", py::arg("E"));
cls_BRepFilletAPI_MakeFillet.def("Length", (Standard_Real (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::Length, "Returns the length of the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("FirstVertex", (TopoDS_Vertex (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::FirstVertex, "Returns the first vertex of the contour of index IC in the internal data structure of this algorithm. Warning Returns a null shape if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("LastVertex", (TopoDS_Vertex (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::LastVertex, "Returns the last vertex of the contour of index IC in the internal data structure of this algorithm. Warning Returns a null shape if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("Abscissa", (Standard_Real (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_MakeFillet::Abscissa, "Returns the curvilinear abscissa of the vertex V on the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if: - IC is outside the bounds of the table of contours, or - V is not on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_MakeFillet.def("RelativeAbscissa", (Standard_Real (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const TopoDS_Vertex &) const) &BRepFilletAPI_MakeFillet::RelativeAbscissa, "Returns the relative curvilinear abscissa (i.e. between 0 and 1) of the vertex V on the contour of index IC in the internal data structure of this algorithm. Warning Returns -1. if: - IC is outside the bounds of the table of contours, or - V is not on the contour of index IC.", py::arg("IC"), py::arg("V"));
cls_BRepFilletAPI_MakeFillet.def("ClosedAndTangent", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::ClosedAndTangent, "Returns true if the contour of index IC in the internal data structure of this algorithm is closed and tangential at the point of closure. Warning Returns false if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("Closed", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::Closed, "Returns true if the contour of index IC in the internal data structure of this algorithm is closed. Warning Returns false if IC is outside the bounds of the table of contours.", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("Build", (void (BRepFilletAPI_MakeFillet::*)()) &BRepFilletAPI_MakeFillet::Build, "Builds the fillets on all the contours in the internal data structure of this algorithm and constructs the resulting shape. Use the function IsDone to verify that the filleted shape is built. Use the function Shape to retrieve the filleted shape. Warning The construction of fillets implements highly complex construction algorithms. Consequently, there may be instances where the algorithm fails, for example if the data defining the radius of the fillet is not compatible with the geometry of the initial shape. There is no initial analysis of errors and they only become evident at the construction stage. Additionally, in the current software release, the following cases are not handled: - the end point of the contour is the point of intersection of 4 or more edges of the shape, or - the intersection of the fillet with a face which limits the contour is not fully contained in this face.");
cls_BRepFilletAPI_MakeFillet.def("Reset", (void (BRepFilletAPI_MakeFillet::*)()) &BRepFilletAPI_MakeFillet::Reset, "Reinitializes this algorithm, thus canceling the effects of the Build function. This function allows modifications to be made to the contours and fillet parameters in order to rebuild the shape.");
cls_BRepFilletAPI_MakeFillet.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::Builder, "Returns the internal topology building algorithm.");
cls_BRepFilletAPI_MakeFillet.def("Generated", (const TopTools_ListOfShape & (BRepFilletAPI_MakeFillet::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeFillet::Generated, "Returns the list of shapes generated from the shape <EorV>.", py::arg("EorV"));
cls_BRepFilletAPI_MakeFillet.def("Modified", (const TopTools_ListOfShape & (BRepFilletAPI_MakeFillet::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeFillet::Modified, "Returns the list of shapes modified from the shape <F>.", py::arg("F"));
cls_BRepFilletAPI_MakeFillet.def("IsDeleted", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)(const TopoDS_Shape &)) &BRepFilletAPI_MakeFillet::IsDeleted, "None", py::arg("F"));
cls_BRepFilletAPI_MakeFillet.def("NbSurfaces", (Standard_Integer (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::NbSurfaces, "returns the number of surfaces after the shape creation.");
cls_BRepFilletAPI_MakeFillet.def("NewFaces", (const TopTools_ListOfShape & (BRepFilletAPI_MakeFillet::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet::NewFaces, "Return the faces created for surface <I>.", py::arg("I"));
cls_BRepFilletAPI_MakeFillet.def("Simulate", (void (BRepFilletAPI_MakeFillet::*)(const Standard_Integer)) &BRepFilletAPI_MakeFillet::Simulate, "None", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("NbSurf", (Standard_Integer (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::NbSurf, "None", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("Sect", (opencascade::handle<ChFiDS_SecHArray1> (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_MakeFillet::Sect, "None", py::arg("IC"), py::arg("IS"));
cls_BRepFilletAPI_MakeFillet.def("NbFaultyContours", (Standard_Integer (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::NbFaultyContours, "Returns the number of contours where the computation of the fillet failed");
cls_BRepFilletAPI_MakeFillet.def("FaultyContour", (Standard_Integer (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::FaultyContour, "for each I in [1.. NbFaultyContours] returns the index IC of the contour where the computation of the fillet failed. the method NbEdges(IC) gives the number of edges in the contour IC the method Edge(IC,ie) gives the edge number ie of the contour IC", py::arg("I"));
cls_BRepFilletAPI_MakeFillet.def("NbComputedSurfaces", (Standard_Integer (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::NbComputedSurfaces, "returns the number of surfaces which have been computed on the contour IC", py::arg("IC"));
cls_BRepFilletAPI_MakeFillet.def("ComputedSurface", (opencascade::handle<Geom_Surface> (BRepFilletAPI_MakeFillet::*)(const Standard_Integer, const Standard_Integer) const) &BRepFilletAPI_MakeFillet::ComputedSurface, "returns the surface number IS concerning the contour IC", py::arg("IC"), py::arg("IS"));
cls_BRepFilletAPI_MakeFillet.def("NbFaultyVertices", (Standard_Integer (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::NbFaultyVertices, "returns the number of vertices where the computation failed");
cls_BRepFilletAPI_MakeFillet.def("FaultyVertex", (TopoDS_Vertex (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::FaultyVertex, "returns the vertex where the computation failed", py::arg("IV"));
cls_BRepFilletAPI_MakeFillet.def("HasResult", (Standard_Boolean (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::HasResult, "returns true if a part of the result has been computed if the filling in a corner failed a shape with a hole is returned");
cls_BRepFilletAPI_MakeFillet.def("BadShape", (TopoDS_Shape (BRepFilletAPI_MakeFillet::*)() const) &BRepFilletAPI_MakeFillet::BadShape, "if (HasResult()) returns the partial result");
cls_BRepFilletAPI_MakeFillet.def("StripeStatus", (ChFiDS_ErrorStatus (BRepFilletAPI_MakeFillet::*)(const Standard_Integer) const) &BRepFilletAPI_MakeFillet::StripeStatus, "returns the status concerning the contour IC in case of error ChFiDS_Ok : the computation is Ok ChFiDS_StartsolFailure : the computation can't start, perhaps the the radius is too big ChFiDS_TwistedSurface : the computation failed because of a twisted surface ChFiDS_WalkingFailure : there is a problem in the walking ChFiDS_Error: other error different from above", py::arg("IC"));

// Enums

}