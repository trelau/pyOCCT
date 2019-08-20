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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_SequenceOfEdgeFaceAndOrder.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <GeomPlate_BuildPlateSurface.hxx>
#include <BRepFill_SequenceOfFaceAndOrder.hxx>
#include <GeomPlate_SequenceOfPointConstraint.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFill_Filling.hxx>

void bind_BRepFill_Filling(py::module &mod){

py::class_<BRepFill_Filling, std::unique_ptr<BRepFill_Filling>> cls_BRepFill_Filling(mod, "BRepFill_Filling", "N-Side Filling This algorithm avoids to build a face from: * a set of edges defining the bounds of the face and some constraints the surface support has to satisfy * a set of edges and points defining some constraints the support surface has to satisfy * an initial surface to deform for satisfying the constraints * a set of parameters to control the constraints.");

// Constructors
cls_BRepFill_Filling.def(py::init<>());
cls_BRepFill_Filling.def(py::init<const Standard_Integer>(), py::arg("Degree"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"));
cls_BRepFill_Filling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"), py::arg("MaxSegments"));

// Fields

// Methods
// cls_BRepFill_Filling.def_static("operator new_", (void * (*)(size_t)) &BRepFill_Filling::operator new, "None", py::arg("theSize"));
// cls_BRepFill_Filling.def_static("operator delete_", (void (*)(void *)) &BRepFill_Filling::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_Filling.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_Filling::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_Filling.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_Filling::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_Filling.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_Filling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_Filling.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_Filling::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self) -> void { return self.SetConstrParam(); });
cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0) -> void { return self.SetConstrParam(a0); });
cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetConstrParam(a0, a1); });
cls_BRepFill_Filling.def("SetConstrParam", [](BRepFill_Filling &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetConstrParam(a0, a1, a2); });
cls_BRepFill_Filling.def("SetConstrParam", (void (BRepFill_Filling::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepFill_Filling::SetConstrParam, "Sets the values of Tolerances used to control the constraint. Tol2d: Tol3d: it is the maximum distance allowed between the support surface and the constraints TolAng: it is the maximum angle allowed between the normal of the surface and the constraints TolCurv: it is the maximum difference of curvature allowed between the surface and the constraint", py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self) -> void { return self.SetResolParam(); });
cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0) -> void { return self.SetResolParam(a0); });
cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetResolParam(a0, a1); });
cls_BRepFill_Filling.def("SetResolParam", [](BRepFill_Filling &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.SetResolParam(a0, a1, a2); });
cls_BRepFill_Filling.def("SetResolParam", (void (BRepFill_Filling::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &BRepFill_Filling::SetResolParam, "Sets the parameters used for resolution. The default values of these parameters have been chosen for a good ratio quality/performance. Degree: it is the order of energy criterion to minimize for computing the deformation of the surface. The default value is 3 The recommanded value is i+2 where i is the maximum order of the constraints. NbPtsOnCur: it is the average number of points for discretisation of the edges. NbIter: it is the maximum number of iterations of the process. For each iteration the number of discretisation points is increased. Anisotropie:", py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepFill_Filling.def("SetApproxParam", [](BRepFill_Filling &self) -> void { return self.SetApproxParam(); });
cls_BRepFill_Filling.def("SetApproxParam", [](BRepFill_Filling &self, const Standard_Integer a0) -> void { return self.SetApproxParam(a0); });
cls_BRepFill_Filling.def("SetApproxParam", (void (BRepFill_Filling::*)(const Standard_Integer, const Standard_Integer)) &BRepFill_Filling::SetApproxParam, "Sets the parameters used for approximation of the surface", py::arg("MaxDeg"), py::arg("MaxSegments"));
cls_BRepFill_Filling.def("LoadInitSurface", (void (BRepFill_Filling::*)(const TopoDS_Face &)) &BRepFill_Filling::LoadInitSurface, "Loads the initial Surface The initial surface must have orthogonal local coordinates, i.e. partial derivatives dS/du and dS/dv must be orthogonal at each point of surface. If this condition breaks, distortions of resulting surface are possible.", py::arg("aFace"));
cls_BRepFill_Filling.def("Add", [](BRepFill_Filling &self, const TopoDS_Edge & a0, const GeomAbs_Shape a1) -> Standard_Integer { return self.Add(a0, a1); });
cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Edge &, const GeomAbs_Shape, const Standard_Boolean)) &BRepFill_Filling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the first face of the edge GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the first face of the edge.", py::arg("anEdge"), py::arg("Order"), py::arg("IsBound"));
cls_BRepFill_Filling.def("Add", [](BRepFill_Filling &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const GeomAbs_Shape a2) -> Standard_Integer { return self.Add(a0, a1, a2); });
cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Edge &, const TopoDS_Face &, const GeomAbs_Shape, const Standard_Boolean)) &BRepFill_Filling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the given face GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the given face.", py::arg("anEdge"), py::arg("Support"), py::arg("Order"), py::arg("IsBound"));
cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const TopoDS_Face &, const GeomAbs_Shape)) &BRepFill_Filling::Add, "Adds a free constraint on a face. The corresponding edge has to be automatically recomputed. It is always a bound.", py::arg("Support"), py::arg("Order"));
cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const gp_Pnt &)) &BRepFill_Filling::Add, "Adds a punctual constraint", py::arg("Point"));
cls_BRepFill_Filling.def("Add", (Standard_Integer (BRepFill_Filling::*)(const Standard_Real, const Standard_Real, const TopoDS_Face &, const GeomAbs_Shape)) &BRepFill_Filling::Add, "Adds a punctual constraint.", py::arg("U"), py::arg("V"), py::arg("Support"), py::arg("Order"));
cls_BRepFill_Filling.def("Build", (void (BRepFill_Filling::*)()) &BRepFill_Filling::Build, "Builds the resulting faces");
cls_BRepFill_Filling.def("IsDone", (Standard_Boolean (BRepFill_Filling::*)() const) &BRepFill_Filling::IsDone, "None");
cls_BRepFill_Filling.def("Face", (TopoDS_Face (BRepFill_Filling::*)() const) &BRepFill_Filling::Face, "None");
cls_BRepFill_Filling.def("Generated", (const TopTools_ListOfShape & (BRepFill_Filling::*)(const TopoDS_Shape &)) &BRepFill_Filling::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepFill_Filling.def("G0Error", (Standard_Real (BRepFill_Filling::*)() const) &BRepFill_Filling::G0Error, "None");
cls_BRepFill_Filling.def("G1Error", (Standard_Real (BRepFill_Filling::*)() const) &BRepFill_Filling::G1Error, "None");
cls_BRepFill_Filling.def("G2Error", (Standard_Real (BRepFill_Filling::*)() const) &BRepFill_Filling::G2Error, "None");
cls_BRepFill_Filling.def("G0Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G0Error, "None", py::arg("Index"));
cls_BRepFill_Filling.def("G1Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G1Error, "None", py::arg("Index"));
cls_BRepFill_Filling.def("G2Error", (Standard_Real (BRepFill_Filling::*)(const Standard_Integer)) &BRepFill_Filling::G2Error, "None", py::arg("Index"));

// Enums

}