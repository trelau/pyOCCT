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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Lin2d.hxx>
#include <Bnd_Box2d.hxx>
#include <gp_Circ.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <BndLib_Add3dCurve.hxx>
#include <BndLib_Add2dCurve.hxx>
#include <BndLib_AddSurface.hxx>
#include <BndLib.hxx>

void bind_BndLib(py::module &mod){

py::class_<BndLib> cls_BndLib(mod, "BndLib", "The BndLib package provides functions to add a geometric primitive to a bounding box. Note: these functions work with gp objects, optionally limited by parameter values. If the curves and surfaces provided by the gp package are not explicitly parameterized, they still have an implicit parameterization, similar to that which they infer for the equivalent Geom or Geom2d objects. Add : Package to compute the bounding boxes for elementary objects from gp in 2d and 3d .");

// Constructors

// Fields

// Methods
// cls_BndLib.def_static("operator new_", (void * (*)(size_t)) &BndLib::operator new, "None", py::arg("theSize"));
// cls_BndLib.def_static("operator delete_", (void (*)(void *)) &BndLib::operator delete, "None", py::arg("theAddress"));
// cls_BndLib.def_static("operator new[]_", (void * (*)(size_t)) &BndLib::operator new[], "None", py::arg("theSize"));
// cls_BndLib.def_static("operator delete[]_", (void (*)(void *)) &BndLib::operator delete[], "None", py::arg("theAddress"));
// cls_BndLib.def_static("operator new_", (void * (*)(size_t, void *)) &BndLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BndLib.def_static("operator delete_", (void (*)(void *, void *)) &BndLib::operator delete, "None", py::arg(""), py::arg(""));
cls_BndLib.def_static("Add_", (void (*)(const gp_Lin &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Bounding box for a surface trimmed or not Adds the segment of the line L limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. Tol is the tolerance value to enlarge the minimun and maximum dimension P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("L"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ2d &, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the circle C, or the arc of the circle C limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips2d &, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "None", py::arg("C"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Elips2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the ellipse E, or the arc of the ellipse E limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P2-P1 can be in [0,2*pi]", py::arg("C"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Parab &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("P"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Parab2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the arc of the parabola P limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("P"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("H"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Hypr2d &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box2d &)) &BndLib::Add, "Adds the arc of the branch of hyperbola H limited by the two parameter values P1 and P2, to the bounding box B, and then enlarges B by the tolerance value Tol. P1 and P2 may represent infinite values. Exceptions Standard_Failure if P1 and P2 are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("H"), py::arg("P1"), py::arg("P2"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "UMax -UMin can be in [0,2*pi]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B, the patch of the cylinder S limited - in the v parametric direction, by the two parameter values VMin and VMax - and optionally in the u parametric direction, by the two parameter values UMin and UMax. B is then enlarged by the tolerance value Tol. VMin and VMax may represent infinite values. Exceptions Standard_Failure if VMin and VMax are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("S"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "UMax-UMin can be in [0,2*pi]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B, the patch of the cone S limited - in the v parametric direction, by the two parameter values VMin and VMax - and optionally in the u parametric direction, by the two parameter values UMin and UMax, B is then enlarged by the tolerance value Tol. VMin and VMax may represent infinite values. Exceptions Standard_Failure if VMin and VMax are either two negative infinite real numbers, or two positive infinite real numbers.", py::arg("S"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Sphere &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("S"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B the sphere S, or - the patch of the sphere S, limited in the u parametric direction, by the two parameter values UMin and UMax, and in the v parametric direction, by the two parameter values VMin and VMax. B is then enlarged by the tolerance value Tol. UMax-UMin can be in [0,2*pi] VMin,VMax can be [-pi/2,pi/2]", py::arg("S"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Torus &, const Standard_Real, Bnd_Box &)) &BndLib::Add, "None", py::arg("P"), py::arg("Tol"), py::arg("B"));
cls_BndLib.def_static("Add_", (void (*)(const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, Bnd_Box &)) &BndLib::Add, "Adds to the bounding box B - the torus S, or - the patch of the torus S, limited in the u parametric direction, by the two parameter values UMin and UMax, and in the v parametric direction, by the two parameter values VMin and VMax. B is then enlarged by the tolerance value Tol. UMax-UMin can be in [0,2*pi], VMin,VMax can be [-pi/2,pi/2]", py::arg("P"), py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"), py::arg("Tol"), py::arg("B"));

// Enums

}