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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepFill_Filling.hxx>
#include <BRepOffsetAPI_MakeFilling.hxx>

void bind_BRepOffsetAPI_MakeFilling(py::module &mod){

py::class_<BRepOffsetAPI_MakeFilling, std::unique_ptr<BRepOffsetAPI_MakeFilling, Deleter<BRepOffsetAPI_MakeFilling>>, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_MakeFilling(mod, "BRepOffsetAPI_MakeFilling", "N-Side Filling This algorithm avoids to build a face from: * a set of edges defining the bounds of the face and some constraints the surface of the face has to satisfy * a set of edges and points defining some constraints the support surface has to satisfy * an initial surface to deform for satisfying the constraints * a set of parameters to control the constraints.");

// Constructors
cls_BRepOffsetAPI_MakeFilling.def(py::init<>());
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer>(), py::arg("Degree"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"));
cls_BRepOffsetAPI_MakeFilling.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"), py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"), py::arg("MaxDeg"), py::arg("MaxSegments"));

// Fields

// Methods
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_MakeFilling::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_MakeFilling::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_MakeFilling::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_MakeFilling::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_MakeFilling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_MakeFilling.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_MakeFilling::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetConstrParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0) -> void { return self.SetConstrParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetConstrParam(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetConstrParam(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("SetConstrParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepOffsetAPI_MakeFilling::SetConstrParam, "Sets the values of Tolerances used to control the constraint. Tol2d: Tol3d: it is the maximum distance allowed between the support surface and the constraints TolAng: it is the maximum angle allowed between the normal of the surface and the constraints TolCurv: it is the maximum difference of curvature allowed between the surface and the constraint", py::arg("Tol2d"), py::arg("Tol3d"), py::arg("TolAng"), py::arg("TolCurv"));
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetResolParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0) -> void { return self.SetResolParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.SetResolParam(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.SetResolParam(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("SetResolParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::SetResolParam, "Sets the parameters used for resolution. The default values of these parameters have been chosen for a good ratio quality/performance. Degree: it is the order of energy criterion to minimize for computing the deformation of the surface. The default value is 3 The recommanded value is i+2 where i is the maximum order of the constraints. NbPtsOnCur: it is the average number of points for discretisation of the edges. NbIter: it is the maximum number of iterations of the process. For each iteration the number of discretisation points is increased. Anisotropie:", py::arg("Degree"), py::arg("NbPtsOnCur"), py::arg("NbIter"), py::arg("Anisotropie"));
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", [](BRepOffsetAPI_MakeFilling &self) -> void { return self.SetApproxParam(); });
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", [](BRepOffsetAPI_MakeFilling &self, const Standard_Integer a0) -> void { return self.SetApproxParam(a0); });
cls_BRepOffsetAPI_MakeFilling.def("SetApproxParam", (void (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer, const Standard_Integer)) &BRepOffsetAPI_MakeFilling::SetApproxParam, "Sets the parameters used to approximate the filling surface. These include: - MaxDeg - the highest degree which the polynomial defining the filling surface can have - MaxSegments - the greatest number of segments which the filling surface can have.", py::arg("MaxDeg"), py::arg("MaxSegments"));
cls_BRepOffsetAPI_MakeFilling.def("LoadInitSurface", (void (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Face &)) &BRepOffsetAPI_MakeFilling::LoadInitSurface, "Loads the initial surface Surf to begin the construction of the surface. This optional function is useful if the surface resulting from construction for the algorithm is likely to be complex. The support surface of the face under construction is computed by a deformation of Surf which satisfies the given constraints. The set of bounding edges defines the wire of the face. If no initial surface is given, the algorithm computes it automatically. If the set of edges is not connected (Free constraint), missing edges are automatically computed. Important: the initial surface must have orthogonal local coordinates, i.e. partial derivatives dS/du and dS/dv must be orthogonal at each point of surface. If this condition breaks, distortions of resulting surface are possible.", py::arg("Surf"));
cls_BRepOffsetAPI_MakeFilling.def("Add", [](BRepOffsetAPI_MakeFilling &self, const TopoDS_Edge & a0, const GeomAbs_Shape a1) -> Standard_Integer { return self.Add(a0, a1); });
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Edge &, const GeomAbs_Shape, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the first face of the edge GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the first face of the edge. Raises ConstructionError if the edge has no representation on a face and Order is GeomAbs_G1 or GeomAbs_G2.", py::arg("Constr"), py::arg("Order"), py::arg("IsBound"));
cls_BRepOffsetAPI_MakeFilling.def("Add", [](BRepOffsetAPI_MakeFilling &self, const TopoDS_Edge & a0, const TopoDS_Face & a1, const GeomAbs_Shape a2) -> Standard_Integer { return self.Add(a0, a1, a2); });
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Edge &, const TopoDS_Face &, const GeomAbs_Shape, const Standard_Boolean)) &BRepOffsetAPI_MakeFilling::Add, "Adds a new constraint which also defines an edge of the wire of the face Order: Order of the constraint: GeomAbs_C0 : the surface has to pass by 3D representation of the edge GeomAbs_G1 : the surface has to pass by 3D representation of the edge and to respect tangency with the given face GeomAbs_G2 : the surface has to pass by 3D representation of the edge and to respect tangency and curvature with the given face. Raises ConstructionError if the edge has no 2d representation on the given face", py::arg("Constr"), py::arg("Support"), py::arg("Order"), py::arg("IsBound"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Face &, const GeomAbs_Shape)) &BRepOffsetAPI_MakeFilling::Add, "Adds a free constraint on a face. The corresponding edge has to be automatically recomputed. It is always a bound.", py::arg("Support"), py::arg("Order"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const gp_Pnt &)) &BRepOffsetAPI_MakeFilling::Add, "Adds a punctual constraint.", py::arg("Point"));
cls_BRepOffsetAPI_MakeFilling.def("Add", (Standard_Integer (BRepOffsetAPI_MakeFilling::*)(const Standard_Real, const Standard_Real, const TopoDS_Face &, const GeomAbs_Shape)) &BRepOffsetAPI_MakeFilling::Add, "Adds a punctual constraint.", py::arg("U"), py::arg("V"), py::arg("Support"), py::arg("Order"));
cls_BRepOffsetAPI_MakeFilling.def("Build", (void (BRepOffsetAPI_MakeFilling::*)()) &BRepOffsetAPI_MakeFilling::Build, "Builds the resulting faces");
cls_BRepOffsetAPI_MakeFilling.def("IsDone", (Standard_Boolean (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::IsDone, "Tests whether computation of the filling plate has been completed.");
cls_BRepOffsetAPI_MakeFilling.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_MakeFilling::*)(const TopoDS_Shape &)) &BRepOffsetAPI_MakeFilling::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_MakeFilling.def("G0Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G0Error, "Returns the maximum distance between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G1Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G1Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G2Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)() const) &BRepOffsetAPI_MakeFilling::G2Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.");
cls_BRepOffsetAPI_MakeFilling.def("G0Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G0Error, "Returns the maximum distance attained between the result and the constraint Index. This is set at construction time.", py::arg("Index"));
cls_BRepOffsetAPI_MakeFilling.def("G1Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G1Error, "Returns the maximum angle between the result and the constraints. This is set at construction time.", py::arg("Index"));
cls_BRepOffsetAPI_MakeFilling.def("G2Error", (Standard_Real (BRepOffsetAPI_MakeFilling::*)(const Standard_Integer)) &BRepOffsetAPI_MakeFilling::G2Error, "Returns the greatest difference in curvature found between the result and the constraint Index.", py::arg("Index"));

// Enums

}