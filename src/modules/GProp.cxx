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
#include <GProp_ValueType.hxx>
#include <GProp_EquaType.hxx>
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <GProp_GProps.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Mat.hxx>
#include <gp_Ax1.hxx>
#include <GProp_PrincipalProps.hxx>
#include <GProp_PGProps.hxx>
#include <GProp_CelGProps.hxx>
#include <GProp_SelGProps.hxx>
#include <GProp_VelGProps.hxx>
#include <GProp_PEquation.hxx>
#include <GProp.hxx>
#include <gp_Circ.hxx>
#include <gp_Lin.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Pln.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_Handle.hxx>
#include <GProp_UndefinedAxis.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(GProp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");

// ENUM: GPROP_VALUETYPE
py::enum_<GProp_ValueType>(mod, "GProp_ValueType", "Algorithmes :")
	.value("GProp_Mass", GProp_ValueType::GProp_Mass)
	.value("GProp_CenterMassX", GProp_ValueType::GProp_CenterMassX)
	.value("GProp_CenterMassY", GProp_ValueType::GProp_CenterMassY)
	.value("GProp_CenterMassZ", GProp_ValueType::GProp_CenterMassZ)
	.value("GProp_InertiaXX", GProp_ValueType::GProp_InertiaXX)
	.value("GProp_InertiaYY", GProp_ValueType::GProp_InertiaYY)
	.value("GProp_InertiaZZ", GProp_ValueType::GProp_InertiaZZ)
	.value("GProp_InertiaXY", GProp_ValueType::GProp_InertiaXY)
	.value("GProp_InertiaXZ", GProp_ValueType::GProp_InertiaXZ)
	.value("GProp_InertiaYZ", GProp_ValueType::GProp_InertiaYZ)
	.value("GProp_Unknown", GProp_ValueType::GProp_Unknown)
	.export_values();


// ENUM: GPROP_EQUATYPE
py::enum_<GProp_EquaType>(mod, "GProp_EquaType", "None")
	.value("GProp_Plane", GProp_EquaType::GProp_Plane)
	.value("GProp_Line", GProp_EquaType::GProp_Line)
	.value("GProp_Point", GProp_EquaType::GProp_Point)
	.value("GProp_Space", GProp_EquaType::GProp_Space)
	.value("GProp_None", GProp_EquaType::GProp_None)
	.export_values();


// CLASS: GPROP_GPROPS
py::class_<GProp_GProps> cls_GProp_GProps(mod, "GProp_GProps", "Implements a general mechanism to compute the global properties of a 'compound geometric system' in 3d space by composition of the global properties of 'elementary geometric entities' such as (curve, surface, solid, set of points). It is possible to compose the properties of several 'compound geometric systems' too.");

// Constructors
cls_GProp_GProps.def(py::init<>());
cls_GProp_GProps.def(py::init<const gp_Pnt &>(), py::arg("SystemLocation"));

// Methods
// cls_GProp_GProps.def_static("operator new_", (void * (*)(size_t)) &GProp_GProps::operator new, "None", py::arg("theSize"));
// cls_GProp_GProps.def_static("operator delete_", (void (*)(void *)) &GProp_GProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_GProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_GProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_GProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_GProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_GProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_GProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_GProps.def("Add", [](GProp_GProps &self, const GProp_GProps & a0) -> void { return self.Add(a0); });
cls_GProp_GProps.def("Add", (void (GProp_GProps::*)(const GProp_GProps &, const Standard_Real)) &GProp_GProps::Add, "Either - initializes the global properties retained by this framework from those retained by the framework Item, or - brings together the global properties still retained by this framework with those retained by the framework Item. The value Density, which is 1.0 by default, is used as the density of the system analysed by Item. Sometimes the density will have already been given at the time of construction of the framework Item. This may be the case for example, if Item is a GProp_PGProps framework built to compute the global properties of a set of points ; or another GProp_GProps object which already retains composite global properties. In these cases the real density was perhaps already taken into account at the time of construction of Item. Note that this is not checked: if the density of parts of the system is taken into account two or more times, results of the computation will be false. Notes : - The point relative to which the inertia of Item is computed (i.e. the reference point of Item) may be different from the reference point in this framework. Huygens' theorem is applied automatically to transfer inertia values to the reference point in this framework. - The function Add is used once per component of the system. After that, you use the interrogation functions available to access values computed for the system. - The system whose global properties are already brought together by this framework is referred to as the current system. However, the current system is not retained by this framework, which maintains only its global properties. Exceptions Standard_DomainError if Density is less than or equal to gp::Resolution().", py::arg("Item"), py::arg("Density"));
cls_GProp_GProps.def("Mass", (Standard_Real (GProp_GProps::*)() const) &GProp_GProps::Mass, "Returns the mass of the current system. If no density is attached to the components of the current system the returned value corresponds to : - the total length of the edges of the current system if this framework retains only linear properties, as is the case for example, when using only the LinearProperties function to combine properties of lines from shapes, or - the total area of the faces of the current system if this framework retains only surface properties, as is the case for example, when using only the SurfaceProperties function to combine properties of surfaces from shapes, or - the total volume of the solids of the current system if this framework retains only volume properties, as is the case for example, when using only the VolumeProperties function to combine properties of volumes from solids. Warning A length, an area, or a volume is computed in the current data unit system. The mass of a single object is obtained by multiplying its length, its area or its volume by the given density. You must be consistent with respect to the units used.");
cls_GProp_GProps.def("CentreOfMass", (gp_Pnt (GProp_GProps::*)() const) &GProp_GProps::CentreOfMass, "Returns the center of mass of the current system. If the gravitational field is uniform, it is the center of gravity. The coordinates returned for the center of mass are expressed in the absolute Cartesian coordinate system.");
cls_GProp_GProps.def("MatrixOfInertia", (gp_Mat (GProp_GProps::*)() const) &GProp_GProps::MatrixOfInertia, "returns the matrix of inertia. It is a symmetrical matrix. The coefficients of the matrix are the quadratic moments of inertia.");
cls_GProp_GProps.def("StaticMoments", [](GProp_GProps &self, Standard_Real & Ix, Standard_Real & Iy, Standard_Real & Iz){ self.StaticMoments(Ix, Iy, Iz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Ix, Iy, Iz); }, "Returns Ix, Iy, Iz, the static moments of inertia of the current system; i.e. the moments of inertia about the three axes of the Cartesian coordinate system.", py::arg("Ix"), py::arg("Iy"), py::arg("Iz"));
cls_GProp_GProps.def("MomentOfInertia", (Standard_Real (GProp_GProps::*)(const gp_Ax1 &) const) &GProp_GProps::MomentOfInertia, "computes the moment of inertia of the material system about the axis A.", py::arg("A"));
cls_GProp_GProps.def("PrincipalProperties", (GProp_PrincipalProps (GProp_GProps::*)() const) &GProp_GProps::PrincipalProperties, "Computes the principal properties of inertia of the current system. There is always a set of axes for which the products of inertia of a geometric system are equal to 0; i.e. the matrix of inertia of the system is diagonal. These axes are the principal axes of inertia. Their origin is coincident with the center of mass of the system. The associated moments are called the principal moments of inertia. This function computes the eigen values and the eigen vectors of the matrix of inertia of the system. Results are stored by using a presentation framework of principal properties of inertia (GProp_PrincipalProps object) which may be queried to access the value sought.");
cls_GProp_GProps.def("RadiusOfGyration", (Standard_Real (GProp_GProps::*)(const gp_Ax1 &) const) &GProp_GProps::RadiusOfGyration, "Returns the radius of gyration of the current system about the axis A.", py::arg("A"));

// CLASS: GPROP
py::class_<GProp> cls_GProp(mod, "GProp", "This package defines algorithmes to compute the global properties of a set of points, a curve, a surface, a solid (non infinite region of space delimited with geometric entities), a compound geometric system (heterogeneous composition of the previous entities).");

// Methods
// cls_GProp.def_static("operator new_", (void * (*)(size_t)) &GProp::operator new, "None", py::arg("theSize"));
// cls_GProp.def_static("operator delete_", (void (*)(void *)) &GProp::operator delete, "None", py::arg("theAddress"));
// cls_GProp.def_static("operator new[]_", (void * (*)(size_t)) &GProp::operator new[], "None", py::arg("theSize"));
// cls_GProp.def_static("operator delete[]_", (void (*)(void *)) &GProp::operator delete[], "None", py::arg("theAddress"));
// cls_GProp.def_static("operator new_", (void * (*)(size_t, void *)) &GProp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp.def_static("operator delete_", (void (*)(void *, void *)) &GProp::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp.def_static("HOperator_", (void (*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, gp_Mat &)) &GProp::HOperator, "methods of package Computes the matrix Operator, referred to as the 'Huyghens Operator' of a geometric system at the point Q of the space, using the following data : - Mass, i.e. the mass of the system, - G, the center of mass of the system. The 'Huyghens Operator' is used to compute Inertia/Q, the matrix of inertia of the system at the point Q using Huyghens' theorem : Inertia/Q = Inertia/G + HOperator (Q, G, Mass) where Inertia/G is the matrix of inertia of the system relative to its center of mass as returned by the function MatrixOfInertia on any GProp_GProps object.", py::arg("G"), py::arg("Q"), py::arg("Mass"), py::arg("Operator"));

// CLASS: GPROP_CELGPROPS
py::class_<GProp_CelGProps, GProp_GProps> cls_GProp_CelGProps(mod, "GProp_CelGProps", "Computes the global properties of bounded curves in 3D space. It can be an elementary curve from package gp such as Lin, Circ, Elips, Parab .");

// Constructors
cls_GProp_CelGProps.def(py::init<>());
cls_GProp_CelGProps.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("C"), py::arg("CLocation"));
cls_GProp_CelGProps.def(py::init<const gp_Circ &, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("CLocation"));
cls_GProp_CelGProps.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("CLocation"));

// Methods
// cls_GProp_CelGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_CelGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_CelGProps.def_static("operator delete_", (void (*)(void *)) &GProp_CelGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_CelGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_CelGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_CelGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_CelGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_CelGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_CelGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_CelGProps.def("SetLocation", (void (GProp_CelGProps::*)(const gp_Pnt &)) &GProp_CelGProps::SetLocation, "None", py::arg("CLocation"));
cls_GProp_CelGProps.def("Perform", (void (GProp_CelGProps::*)(const gp_Circ &, const Standard_Real, const Standard_Real)) &GProp_CelGProps::Perform, "None", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GProp_CelGProps.def("Perform", (void (GProp_CelGProps::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &GProp_CelGProps::Perform, "None", py::arg("C"), py::arg("U1"), py::arg("U2"));

// CLASS: GPROP_PEQUATION
py::class_<GProp_PEquation> cls_GProp_PEquation(mod, "GProp_PEquation", "A framework to analyze a collection - or cloud - of points and to verify if they are coincident, collinear or coplanar within a given precision. If so, it also computes the mean point, the mean line or the mean plane of the points. If not, it computes the minimal box which includes all the points.");

// Constructors
cls_GProp_PEquation.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real>(), py::arg("Pnts"), py::arg("Tol"));

// Methods
// cls_GProp_PEquation.def_static("operator new_", (void * (*)(size_t)) &GProp_PEquation::operator new, "None", py::arg("theSize"));
// cls_GProp_PEquation.def_static("operator delete_", (void (*)(void *)) &GProp_PEquation::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PEquation::operator new[], "None", py::arg("theSize"));
// cls_GProp_PEquation.def_static("operator delete[]_", (void (*)(void *)) &GProp_PEquation::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PEquation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PEquation.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PEquation::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PEquation.def("IsPlanar", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsPlanar, "Returns true if, according to the given tolerance, the points analyzed by this framework are coplanar. Use the function Plane to access the computed result.");
cls_GProp_PEquation.def("IsLinear", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsLinear, "Returns true if, according to the given tolerance, the points analyzed by this framework are colinear. Use the function Line to access the computed result.");
cls_GProp_PEquation.def("IsPoint", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsPoint, "Returns true if, according to the given tolerance, the points analyzed by this framework are coincident. Use the function Point to access the computed result.");
cls_GProp_PEquation.def("IsSpace", (Standard_Boolean (GProp_PEquation::*)() const) &GProp_PEquation::IsSpace, "Returns true if, according to the given tolerance value, the points analyzed by this framework are neither coincident, nor collinear, nor coplanar. Use the function Box to query the smallest box that includes the collection of points.");
cls_GProp_PEquation.def("Plane", (gp_Pln (GProp_PEquation::*)() const) &GProp_PEquation::Plane, "Returns the mean plane passing near all the points analyzed by this framework if, according to the given precision, the points are considered to be coplanar. Exceptions Standard_NoSuchObject if, according to the given precision value, the points analyzed by this framework are considered to be: - coincident, or - collinear, or - not coplanar.");
cls_GProp_PEquation.def("Line", (gp_Lin (GProp_PEquation::*)() const) &GProp_PEquation::Line, "Returns the mean line passing near all the points analyzed by this framework if, according to the given precision value, the points are considered to be collinear. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are considered to be: - coincident, or - not collinear.");
cls_GProp_PEquation.def("Point", (gp_Pnt (GProp_PEquation::*)() const) &GProp_PEquation::Point, "Returns the mean point of all the points analyzed by this framework if, according to the given precision, the points are considered to be coincident. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are not considered to be coincident.");
cls_GProp_PEquation.def("Box", (void (GProp_PEquation::*)(gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GProp_PEquation::Box, "Returns the definition of the smallest box which contains all the points analyzed by this framework if, according to the given precision value, the points are considered to be neither coincident, nor collinear and nor coplanar. This box is centered on the barycenter P of the collection of points. Its sides are parallel to the three vectors V1, V2 and V3, the length of which is the length of the box in the corresponding direction. Note: Vectors V1, V2 and V3 are parallel to the three axes of principal inertia of the system composed of the collection of points where each point is of equal mass. Exceptions Standard_NoSuchObject if, according to the given precision, the points analyzed by this framework are considered to be coincident, collinear or coplanar.", py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));

// CLASS: GPROP_PGPROPS
py::class_<GProp_PGProps, GProp_GProps> cls_GProp_PGProps(mod, "GProp_PGProps", "A framework for computing the global properties of a set of points. A point mass is attached to each point. The global mass of the system is the sum of each individual mass. By default, the point mass is equal to 1 and the mass of a system composed of N points is equal to N. Warning A framework of this sort provides functions to handle sets of points easily. But, like any GProp_GProps object, by using the Add function, it can theoretically bring together the computed global properties and those of a system more complex than a set of points . The mass of each point and the density of each component of the composed system must be coherent. Note that this coherence cannot be checked. Nonetheless, you are advised to restrict your use of a GProp_PGProps object to a set of points and to create a GProp_GProps object in order to bring together global properties of different systems.");

// Constructors
cls_GProp_PGProps.def(py::init<>());
cls_GProp_PGProps.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Pnts"));
cls_GProp_PGProps.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("Pnts"));
cls_GProp_PGProps.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Pnts"), py::arg("Density"));
cls_GProp_PGProps.def(py::init<const TColgp_Array2OfPnt &, const TColStd_Array2OfReal &>(), py::arg("Pnts"), py::arg("Density"));

// Methods
// cls_GProp_PGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_PGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_PGProps.def_static("operator delete_", (void (*)(void *)) &GProp_PGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_PGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_PGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PGProps.def("AddPoint", (void (GProp_PGProps::*)(const gp_Pnt &)) &GProp_PGProps::AddPoint, "Brings together the global properties already retained by this framework with those induced by the point Pnt. Pnt may be the first point of the current system. A point mass is attached to the point Pnt, it is either equal to 1. or to Density.", py::arg("P"));
cls_GProp_PGProps.def("AddPoint", (void (GProp_PGProps::*)(const gp_Pnt &, const Standard_Real)) &GProp_PGProps::AddPoint, "Adds a new point P with its density in the system of points Exceptions Standard_DomainError if the mass value Density is less than gp::Resolution().", py::arg("P"), py::arg("Density"));
cls_GProp_PGProps.def_static("Barycentre_", (gp_Pnt (*)(const TColgp_Array1OfPnt &)) &GProp_PGProps::Barycentre, "Computes the barycentre of a set of points. The density of the points is defaulted to 1.", py::arg("Pnts"));
cls_GProp_PGProps.def_static("Barycentre_", (gp_Pnt (*)(const TColgp_Array2OfPnt &)) &GProp_PGProps::Barycentre, "Computes the barycentre of a set of points. The density of the points is defaulted to 1.", py::arg("Pnts"));
cls_GProp_PGProps.def_static("Barycentre_", [](const TColgp_Array1OfPnt & Pnts, const TColStd_Array1OfReal & Density, Standard_Real & Mass, gp_Pnt & G){ GProp_PGProps::Barycentre(Pnts, Density, Mass, G); return Mass; }, "Computes the barycentre of a set of points. A density is associated with each point.", py::arg("Pnts"), py::arg("Density"), py::arg("Mass"), py::arg("G"));
cls_GProp_PGProps.def_static("Barycentre_", [](const TColgp_Array2OfPnt & Pnts, const TColStd_Array2OfReal & Density, Standard_Real & Mass, gp_Pnt & G){ GProp_PGProps::Barycentre(Pnts, Density, Mass, G); return Mass; }, "Computes the barycentre of a set of points. A density is associated with each point.", py::arg("Pnts"), py::arg("Density"), py::arg("Mass"), py::arg("G"));

// CLASS: GPROP_PRINCIPALPROPS
py::class_<GProp_PrincipalProps> cls_GProp_PrincipalProps(mod, "GProp_PrincipalProps", "A framework to present the principal properties of inertia of a system of which global properties are computed by a GProp_GProps object. There is always a set of axes for which the products of inertia of a geometric system are equal to 0; i.e. the matrix of inertia of the system is diagonal. These axes are the principal axes of inertia. Their origin is coincident with the center of mass of the system. The associated moments are called the principal moments of inertia. This sort of presentation object is created, filled and returned by the function PrincipalProperties for any GProp_GProps object, and can be queried to access the result. Note: The system whose principal properties of inertia are returned by this framework is referred to as the current system. The current system, however, is retained neither by this presentation framework nor by the GProp_GProps object which activates it.");

// Constructors
cls_GProp_PrincipalProps.def(py::init<>());

// Methods
// cls_GProp_PrincipalProps.def_static("operator new_", (void * (*)(size_t)) &GProp_PrincipalProps::operator new, "None", py::arg("theSize"));
// cls_GProp_PrincipalProps.def_static("operator delete_", (void (*)(void *)) &GProp_PrincipalProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_PrincipalProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_PrincipalProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_PrincipalProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_PrincipalProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_PrincipalProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_PrincipalProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_PrincipalProps.def("HasSymmetryAxis", (Standard_Boolean (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::HasSymmetryAxis, "returns true if the geometric system has an axis of symmetry. For comparing moments relative tolerance 1.e-10 is used. Usually it is enough for objects, restricted by faces with analitycal geometry.");
cls_GProp_PrincipalProps.def("HasSymmetryAxis", (Standard_Boolean (GProp_PrincipalProps::*)(const Standard_Real) const) &GProp_PrincipalProps::HasSymmetryAxis, "returns true if the geometric system has an axis of symmetry. aTol is relative tolerance for cheking equality of moments If aTol == 0, relative tolerance is ~ 1.e-16 (Epsilon(I))", py::arg("aTol"));
cls_GProp_PrincipalProps.def("HasSymmetryPoint", (Standard_Boolean (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::HasSymmetryPoint, "returns true if the geometric system has a point of symmetry. For comparing moments relative tolerance 1.e-10 is used. Usually it is enough for objects, restricted by faces with analitycal geometry.");
cls_GProp_PrincipalProps.def("HasSymmetryPoint", (Standard_Boolean (GProp_PrincipalProps::*)(const Standard_Real) const) &GProp_PrincipalProps::HasSymmetryPoint, "returns true if the geometric system has a point of symmetry. aTol is relative tolerance for cheking equality of moments If aTol == 0, relative tolerance is ~ 1.e-16 (Epsilon(I))", py::arg("aTol"));
cls_GProp_PrincipalProps.def("Moments", [](GProp_PrincipalProps &self, Standard_Real & Ixx, Standard_Real & Iyy, Standard_Real & Izz){ self.Moments(Ixx, Iyy, Izz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Ixx, Iyy, Izz); }, "Ixx, Iyy and Izz return the principal moments of inertia in the current system. Notes : - If the current system has an axis of symmetry, two of the three values Ixx, Iyy and Izz are equal. They indicate which eigen vectors define an infinity of axes of principal inertia. - If the current system has a center of symmetry, Ixx, Iyy and Izz are equal.", py::arg("Ixx"), py::arg("Iyy"), py::arg("Izz"));
cls_GProp_PrincipalProps.def("FirstAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::FirstAxisOfInertia, "returns the first axis of inertia.");
cls_GProp_PrincipalProps.def("SecondAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::SecondAxisOfInertia, "returns the second axis of inertia.");
cls_GProp_PrincipalProps.def("ThirdAxisOfInertia", (const gp_Vec & (GProp_PrincipalProps::*)() const) &GProp_PrincipalProps::ThirdAxisOfInertia, "returns the third axis of inertia. This and the above functions return the first, second or third eigen vector of the matrix of inertia of the current system. The first, second and third principal axis of inertia pass through the center of mass of the current system. They are respectively parallel to these three eigen vectors. Note that: - If the current system has an axis of symmetry, any axis is an axis of principal inertia if it passes through the center of mass of the system, and runs parallel to a linear combination of the two eigen vectors of the matrix of inertia, corresponding to the two eigen values which are equal. If the current system has a center of symmetry, any axis passing through the center of mass of the system is an axis of principal inertia. Use the functions HasSymmetryAxis and HasSymmetryPoint to check these particular cases, where the returned eigen vectors define an infinity of principal axis of inertia. - The Moments function can be used to know which of the three eigen vectors corresponds to the two eigen values which are equal.");
cls_GProp_PrincipalProps.def("RadiusOfGyration", [](GProp_PrincipalProps &self, Standard_Real & Rxx, Standard_Real & Ryy, Standard_Real & Rzz){ self.RadiusOfGyration(Rxx, Ryy, Rzz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Rxx, Ryy, Rzz); }, "Returns the principal radii of gyration Rxx, Ryy and Rzz are the radii of gyration of the current system about its three principal axes of inertia. Note that: - If the current system has an axis of symmetry, two of the three values Rxx, Ryy and Rzz are equal. - If the current system has a center of symmetry, Rxx, Ryy and Rzz are equal.", py::arg("Rxx"), py::arg("Ryy"), py::arg("Rzz"));

// CLASS: GPROP_SELGPROPS
py::class_<GProp_SelGProps, GProp_GProps> cls_GProp_SelGProps(mod, "GProp_SelGProps", "Computes the global properties of a bounded elementary surface in 3d (surface of the gp package)");

// Constructors
cls_GProp_SelGProps.def(py::init<>());
cls_GProp_SelGProps.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("SLocation"));
cls_GProp_SelGProps.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("SLocation"));

// Methods
// cls_GProp_SelGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_SelGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_SelGProps.def_static("operator delete_", (void (*)(void *)) &GProp_SelGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_SelGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_SelGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_SelGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_SelGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_SelGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_SelGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_SelGProps.def("SetLocation", (void (GProp_SelGProps::*)(const gp_Pnt &)) &GProp_SelGProps::SetLocation, "None", py::arg("SLocation"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));
cls_GProp_SelGProps.def("Perform", (void (GProp_SelGProps::*)(const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_SelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));

// CLASS: GPROP_UNDEFINEDAXIS
py::class_<GProp_UndefinedAxis, opencascade::handle<GProp_UndefinedAxis>, Standard_DomainError> cls_GProp_UndefinedAxis(mod, "GProp_UndefinedAxis", "This exception is raised when a method makes reference to an undefined inertia axis of symmetry.");

// Constructors
cls_GProp_UndefinedAxis.def(py::init<>());
cls_GProp_UndefinedAxis.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_GProp_UndefinedAxis.def_static("Raise_", (void (*)(const Standard_CString)) &GProp_UndefinedAxis::Raise, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("Raise_", (void (*)(Standard_SStream &)) &GProp_UndefinedAxis::Raise, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("NewInstance_", (opencascade::handle<GProp_UndefinedAxis> (*)(const Standard_CString)) &GProp_UndefinedAxis::NewInstance, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("get_type_name_", (const char * (*)()) &GProp_UndefinedAxis::get_type_name, "None");
cls_GProp_UndefinedAxis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GProp_UndefinedAxis::get_type_descriptor, "None");
cls_GProp_UndefinedAxis.def("DynamicType", (const opencascade::handle<Standard_Type> & (GProp_UndefinedAxis::*)() const) &GProp_UndefinedAxis::DynamicType, "None");

// CLASS: GPROP_VELGPROPS
py::class_<GProp_VelGProps, GProp_GProps> cls_GProp_VelGProps(mod, "GProp_VelGProps", "Computes the global properties and the volume of a geometric solid (3D closed region of space) The solid can be elementary(definition in the gp package)");

// Constructors
cls_GProp_VelGProps.def(py::init<>());
cls_GProp_VelGProps.def(py::init<const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("VLocation"));
cls_GProp_VelGProps.def(py::init<const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"), py::arg("VLocation"));
cls_GProp_VelGProps.def(py::init<const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("VLocation"));
cls_GProp_VelGProps.def(py::init<const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &>(), py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("VLocation"));

// Methods
// cls_GProp_VelGProps.def_static("operator new_", (void * (*)(size_t)) &GProp_VelGProps::operator new, "None", py::arg("theSize"));
// cls_GProp_VelGProps.def_static("operator delete_", (void (*)(void *)) &GProp_VelGProps::operator delete, "None", py::arg("theAddress"));
// cls_GProp_VelGProps.def_static("operator new[]_", (void * (*)(size_t)) &GProp_VelGProps::operator new[], "None", py::arg("theSize"));
// cls_GProp_VelGProps.def_static("operator delete[]_", (void (*)(void *)) &GProp_VelGProps::operator delete[], "None", py::arg("theAddress"));
// cls_GProp_VelGProps.def_static("operator new_", (void * (*)(size_t, void *)) &GProp_VelGProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GProp_VelGProps.def_static("operator delete_", (void (*)(void *, void *)) &GProp_VelGProps::operator delete, "None", py::arg(""), py::arg(""));
cls_GProp_VelGProps.def("SetLocation", (void (GProp_VelGProps::*)(const gp_Pnt &)) &GProp_VelGProps::SetLocation, "None", py::arg("VLocation"));
cls_GProp_VelGProps.def("Perform", (void (GProp_VelGProps::*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_VelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_VelGProps.def("Perform", (void (GProp_VelGProps::*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_VelGProps::Perform, "None", py::arg("S"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Z1"), py::arg("Z2"));
cls_GProp_VelGProps.def("Perform", (void (GProp_VelGProps::*)(const gp_Sphere &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_VelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));
cls_GProp_VelGProps.def("Perform", (void (GProp_VelGProps::*)(const gp_Torus &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GProp_VelGProps::Perform, "None", py::arg("S"), py::arg("Teta1"), py::arg("Teta2"), py::arg("Alpha1"), py::arg("Alpha2"));


}
