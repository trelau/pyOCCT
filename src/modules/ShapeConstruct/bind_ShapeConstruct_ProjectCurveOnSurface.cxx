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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeExtend_Status.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeConstruct_ProjectCurveOnSurface.hxx>
#include <Standard_Type.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>

void bind_ShapeConstruct_ProjectCurveOnSurface(py::module &mod){

py::class_<ShapeConstruct_ProjectCurveOnSurface, opencascade::handle<ShapeConstruct_ProjectCurveOnSurface>, Standard_Transient> cls_ShapeConstruct_ProjectCurveOnSurface(mod, "ShapeConstruct_ProjectCurveOnSurface", "This tool provides a method for computing pcurve by projecting 3d curve onto a surface. Projection is done by 23 or more points (this number is changed for B-Splines according to the following rule: the total number of the points is not less than number of spans * (degree + 1); it is increased recursively starting with 23 and is added with 22 until the condition is fulfilled). Isoparametric cases (if curve corresponds to U=const or V=const on the surface) are recognized with the given precision.");

// Constructors
cls_ShapeConstruct_ProjectCurveOnSurface.def(py::init<>());

// Fields

// Methods
cls_ShapeConstruct_ProjectCurveOnSurface.def("Init", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Init, "Initializes the object with all necessary parameters, i.e. surface and precision", py::arg("surf"), py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("Init", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Init, "Initializes the object with all necessary parameters, i.e. surface and precision", py::arg("surf"), py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetSurface", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeConstruct_ProjectCurveOnSurface::SetSurface, "Loads a surface (in the form of Geom_Surface) to project on", py::arg("surf"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetSurface", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<ShapeAnalysis_Surface> &)) &ShapeConstruct_ProjectCurveOnSurface::SetSurface, "Loads a surface (in the form of ShapeAnalysis_Surface) to project on", py::arg("surf"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetPrecision", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::SetPrecision, "Sets value for current precision", py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("BuildCurveMode", (Standard_Boolean & (ShapeConstruct_ProjectCurveOnSurface::*)()) &ShapeConstruct_ProjectCurveOnSurface::BuildCurveMode, "Returns (modifiable) the build-curve-3d mode, by default False If True, if the projected curve has been recomputed by interpolation, the 3d curve is also rebuild by interpolation");
cls_ShapeConstruct_ProjectCurveOnSurface.def("AdjustOverDegenMode", (Standard_Integer & (ShapeConstruct_ProjectCurveOnSurface::*)()) &ShapeConstruct_ProjectCurveOnSurface::AdjustOverDegenMode, "Returns (modifiable) the flag specifying to which side of parametrical space adjust part of pcurve which lies on seam. This is required in very rare case when 3d curve which is to be projected goes partly along the seam on the closed surface with singularity (e.g. sphere), goes through the degenerated point and paerly lies on internal area of surface.");
cls_ShapeConstruct_ProjectCurveOnSurface.def("Status", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(const ShapeExtend_Status) const) &ShapeConstruct_ProjectCurveOnSurface::Status, "Returns the status of last Peform", py::arg("theStatus"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3) -> Standard_Boolean { return self.Perform(a0, a1, a2, a3); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const Standard_Real a4) -> Standard_Boolean { return self.Perform(a0, a1, a2, a3, a4); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Perform, "Computes the projection of 3d curve onto a surface using the specialized algorithm. Returns False if projector fails, otherwise, if pcurve computed successfully, returns True. The output curve 2D is guaranteed to be same-parameter with input curve 3D on the interval [First, Last]. If the output curve lies on a direct line the infinite line is returned, in the case same-parameter condition is satisfied. TolFirst and TolLast are the tolerances at the ends of input curve 3D.", py::arg("c3d"), py::arg("First"), py::arg("Last"), py::arg("c2d"), py::arg("TolFirst"), py::arg("TolLast"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const GeomAbs_Shape a4) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3, a4); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const GeomAbs_Shape a4, const Standard_Integer a5) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3, a4, a5); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &ShapeConstruct_ProjectCurveOnSurface::PerformByProjLib, "Computes the projection of 3d curve onto a surface using the standard algorithm from ProjLib. Returns False if standard projector fails or raises an exception or cuts the curve by parametrical bounds of the surface. Else, if pcurve computed successfully, returns True. The continuity, maxdeg and nbinterval are parameters of call to Approx_CurveOnSurface. If nbinterval is equal to -1 (default), this value is computed depending on source 3d curve and surface.", py::arg("c3d"), py::arg("First"), py::arg("Last"), py::arg("c2d"), py::arg("continuity"), py::arg("maxdeg"), py::arg("nbinterval"));
cls_ShapeConstruct_ProjectCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &ShapeConstruct_ProjectCurveOnSurface::get_type_name, "None");
cls_ShapeConstruct_ProjectCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeConstruct_ProjectCurveOnSurface::get_type_descriptor, "None");
cls_ShapeConstruct_ProjectCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeConstruct_ProjectCurveOnSurface::*)() const) &ShapeConstruct_ProjectCurveOnSurface::DynamicType, "None");

// Enums

}