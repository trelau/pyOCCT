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
#include <gp_Pnt2d.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Hypr.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <ProjLib_ProjectedCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <ProjLib_ProjectOnPlane.hxx>
#include <ProjLib_ProjectOnSurface.hxx>
#include <ProjLib_ComputeApprox.hxx>
#include <ProjLib_ComputeApproxOnPolarSurface.hxx>
#include <ProjLib_HProjectedCurve.hxx>
#include <ProjLib_CompProjectedCurve.hxx>
#include <ProjLib_HCompProjectedCurve.hxx>
#include <ProjLib_PrjResolve.hxx>
#include <ProjLib_PrjFunc.hxx>
#include <ProjLib_Projector.hxx>
#include <ProjLib_Plane.hxx>
#include <ProjLib_Cylinder.hxx>
#include <ProjLib_Cone.hxx>
#include <ProjLib_Sphere.hxx>
#include <ProjLib_Torus.hxx>
#include <ProjLib.hxx>

void bind_ProjLib(py::module &mod){

py::class_<ProjLib> cls_ProjLib(mod, "ProjLib", "The projLib package first provides projection of curves on a plane along a given Direction. The result will be a 3D curve. The ProjLib package provides projection of curves on surfaces to compute the curve in the parametric space.");

// Constructors

// Fields

// Methods
// cls_ProjLib.def_static("operator new_", (void * (*)(size_t)) &ProjLib::operator new, "None", py::arg("theSize"));
// cls_ProjLib.def_static("operator delete_", (void (*)(void *)) &ProjLib::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib::operator new[], "None", py::arg("theSize"));
// cls_ProjLib.def_static("operator delete[]_", (void (*)(void *)) &ProjLib::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib::operator delete, "None", py::arg(""), py::arg(""));
cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Pln &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Pln &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("L"));
cls_ProjLib.def_static("Project_", (gp_Circ2d (*)(const gp_Pln &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("C"));
cls_ProjLib.def_static("Project_", (gp_Elips2d (*)(const gp_Pln &, const gp_Elips &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("E"));
cls_ProjLib.def_static("Project_", (gp_Parab2d (*)(const gp_Pln &, const gp_Parab &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Hypr2d (*)(const gp_Pln &, const gp_Hypr &)) &ProjLib::Project, "None", py::arg("Pl"), py::arg("H"));
cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Cylinder &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cylinder &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("L"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cylinder &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Cy"), py::arg("Ci"));
cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Cone &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cone &, const gp_Lin &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("L"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Cone &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Co"), py::arg("Ci"));
cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Sphere &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("Sp"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Sphere &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("Sp"), py::arg("Ci"));
cls_ProjLib.def_static("Project_", (gp_Pnt2d (*)(const gp_Torus &, const gp_Pnt &)) &ProjLib::Project, "None", py::arg("To"), py::arg("P"));
cls_ProjLib.def_static("Project_", (gp_Lin2d (*)(const gp_Torus &, const gp_Circ &)) &ProjLib::Project, "None", py::arg("To"), py::arg("Ci"));
cls_ProjLib.def_static("MakePCurveOfType_", (void (*)(const ProjLib_ProjectedCurve &, opencascade::handle<Geom2d_Curve> &)) &ProjLib::MakePCurveOfType, "Make empty P-Curve <aC> of relevant to <PC> type", py::arg("PC"), py::arg("aC"));
cls_ProjLib.def_static("IsAnaSurf_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib::IsAnaSurf, "Returns 'true' if surface is analytical, that is it can be Plane, Cylinder, Cone, Sphere, Torus. For all other types of surface method returns 'false'.", py::arg("theAS"));

// Enums

}