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
#include <VrmlConverter_TypeOfCamera.hxx>
#include <VrmlConverter_TypeOfLight.hxx>
#include <Standard.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <VrmlConverter_Drawer.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlConverter_Curve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <VrmlConverter_DeflectionCurve.hxx>
#include <Standard_Transient.hxx>
#include <Aspect_TypeOfDeflection.hxx>
#include <VrmlConverter_IsoAspect.hxx>
#include <VrmlConverter_LineAspect.hxx>
#include <VrmlConverter_PointAspect.hxx>
#include <VrmlConverter_ShadingAspect.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <VrmlConverter_Projector.hxx>
#include <VrmlConverter_HLRShape.hxx>
#include <Vrml_Material.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Vrml_PerspectiveCamera.hxx>
#include <Vrml_OrthographicCamera.hxx>
#include <Vrml_DirectionalLight.hxx>
#include <Vrml_PointLight.hxx>
#include <Vrml_SpotLight.hxx>
#include <Vrml_MatrixTransform.hxx>
#include <TopoDS_Face.hxx>
#include <Poly_Connect.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <VrmlConverter_ShadedShape.hxx>
#include <Vrml_ShapeHints.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <VrmlConverter_WFDeflectionRestrictedFace.hxx>
#include <VrmlConverter_WFDeflectionShape.hxx>
#include <VrmlConverter_WFRestrictedFace.hxx>
#include <VrmlConverter_WFShape.hxx>

PYBIND11_MODULE(VrmlConverter, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Vrml");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.Poly");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRepAdaptor");

// ENUM: VRMLCONVERTER_TYPEOFCAMERA
py::enum_<VrmlConverter_TypeOfCamera>(mod, "VrmlConverter_TypeOfCamera", "None")
	.value("VrmlConverter_NoCamera", VrmlConverter_TypeOfCamera::VrmlConverter_NoCamera)
	.value("VrmlConverter_PerspectiveCamera", VrmlConverter_TypeOfCamera::VrmlConverter_PerspectiveCamera)
	.value("VrmlConverter_OrthographicCamera", VrmlConverter_TypeOfCamera::VrmlConverter_OrthographicCamera)
	.export_values();


// ENUM: VRMLCONVERTER_TYPEOFLIGHT
py::enum_<VrmlConverter_TypeOfLight>(mod, "VrmlConverter_TypeOfLight", "None")
	.value("VrmlConverter_NoLight", VrmlConverter_TypeOfLight::VrmlConverter_NoLight)
	.value("VrmlConverter_DirectionLight", VrmlConverter_TypeOfLight::VrmlConverter_DirectionLight)
	.value("VrmlConverter_PointLight", VrmlConverter_TypeOfLight::VrmlConverter_PointLight)
	.value("VrmlConverter_SpotLight", VrmlConverter_TypeOfLight::VrmlConverter_SpotLight)
	.export_values();


// CLASS: VRMLCONVERTER_CURVE
py::class_<VrmlConverter_Curve> cls_VrmlConverter_Curve(mod, "VrmlConverter_Curve", "Curve - computes the presentation of objects to be seen as curves (the computation will be made with a constant number of points), converts this one into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer of Drawer class (VrmlConverter). This kind of the presentation is converted into IndexedLineSet ( VRML ).");

// Methods
// cls_VrmlConverter_Curve.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_Curve::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_Curve.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_Curve::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_Curve::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_Curve.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_Curve.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const opencascade::handle<VrmlConverter_Drawer> &, Standard_OStream &)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer.", py::arg("aCurve"), py::arg("aDrawer"), py::arg("anOStream"));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<VrmlConverter_Drawer> &, Standard_OStream &)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer. The drawing will be limited between the points of parameter U1 and U2.", py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"), py::arg("anOStream"));
cls_VrmlConverter_Curve.def_static("Add_", (void (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, Standard_OStream &, const Standard_Integer)) &VrmlConverter_Curve::Add, "adds to the OStream the drawing of the curve aCurve. The aspect is the current aspect. The drawing will be limited between the points of parameter U1 and U2. aNbPoints defines number of points on one interval.", py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("anOStream"), py::arg("aNbPoints"));

// CLASS: VRMLCONVERTER_DEFLECTIONCURVE
py::class_<VrmlConverter_DeflectionCurve> cls_VrmlConverter_DeflectionCurve(mod, "VrmlConverter_DeflectionCurve", "DeflectionCurve - computes the presentation of objects to be seen as curves, converts this one into VRML objects and writes (adds) into anOStream. All requested properties of the representation are specify in aDrawer. This kind of the presentation is converted into IndexedLineSet ( VRML ). The computation will be made according to a maximal chordial deviation.");

// Methods
// cls_VrmlConverter_DeflectionCurve.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_DeflectionCurve::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_DeflectionCurve.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_DeflectionCurve::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_DeflectionCurve.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_DeflectionCurve::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_DeflectionCurve.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_DeflectionCurve::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_DeflectionCurve.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_DeflectionCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_DeflectionCurve.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_DeflectionCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, Adaptor3d_Curve &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with respect to the maximal chordial deviation defined by the drawer aDrawer. The aspect is defined by LineAspect in aDrawer.", py::arg("anOStream"), py::arg("aCurve"), py::arg("aDrawer"));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with respect to the maximal chordial deviation defined by the drawer aDrawer. The aspect is defined by LineAspect in aDrawer. The drawing will be limited between the points of parameter U1 and U2.", py::arg("anOStream"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect", py::arg("anOStream"), py::arg("aCurve"), py::arg("aDeflection"), py::arg("aLimit"));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, Adaptor3d_Curve &, const Standard_Real, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect", py::arg("anOStream"), py::arg("aCurve"), py::arg("aDeflection"), py::arg("aDrawer"));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect The drawing will be limited between the points of parameter U1 and U2.", py::arg("anOStream"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDeflection"));
cls_VrmlConverter_DeflectionCurve.def_static("Add_", (void (*)(Standard_OStream &, const Adaptor3d_Curve &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Integer, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_DeflectionCurve::Add, "adds to the OStream the drawing of the curve aCurve with the array of parameters to retrieve points on curve.", py::arg("anOStream"), py::arg("aCurve"), py::arg("aParams"), py::arg("aNbNodes"), py::arg("aDrawer"));

// CLASS: VRMLCONVERTER_DRAWER
py::class_<VrmlConverter_Drawer, opencascade::handle<VrmlConverter_Drawer>, Standard_Transient> cls_VrmlConverter_Drawer(mod, "VrmlConverter_Drawer", "qualifies the aspect properties for the VRML conversation of a specific kind of object. This includes for example color, maximal chordial deviation, etc...");

// Constructors
cls_VrmlConverter_Drawer.def(py::init<>());

// Methods
cls_VrmlConverter_Drawer.def("SetTypeOfDeflection", (void (VrmlConverter_Drawer::*)(const Aspect_TypeOfDeflection)) &VrmlConverter_Drawer::SetTypeOfDeflection, "by default: TOD_Relative; however, except for the shapes, the drawing will be made using the absolute deviation.", py::arg("aTypeOfDeflection"));
cls_VrmlConverter_Drawer.def("TypeOfDeflection", (Aspect_TypeOfDeflection (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::TypeOfDeflection, "None");
cls_VrmlConverter_Drawer.def("SetMaximalChordialDeviation", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetMaximalChordialDeviation, "Defines the maximal chordial deviation when drawing any curve; If this value is one of the obvious parameters of methods, current value from Drawer won't be used. This value is used by:", py::arg("aChordialDeviation"));
cls_VrmlConverter_Drawer.def("MaximalChordialDeviation", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::MaximalChordialDeviation, "returns the maximal chordial deviation. Default value: 0.1");
cls_VrmlConverter_Drawer.def("SetDeviationCoefficient", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetDeviationCoefficient, "default 0.001", py::arg("aCoefficient"));
cls_VrmlConverter_Drawer.def("DeviationCoefficient", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DeviationCoefficient, "None");
cls_VrmlConverter_Drawer.def("SetDiscretisation", (void (VrmlConverter_Drawer::*)(const Standard_Integer)) &VrmlConverter_Drawer::SetDiscretisation, "default: 17 points. Defines the Discretisation (myNbPoints) when drawing any curve; If this value is one of the obvious parameters of methods, current value from Drawer won't be used. This value is used by:", py::arg("d"));
cls_VrmlConverter_Drawer.def("Discretisation", (Standard_Integer (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::Discretisation, "None");
cls_VrmlConverter_Drawer.def("SetMaximalParameterValue", (void (VrmlConverter_Drawer::*)(const Standard_Real)) &VrmlConverter_Drawer::SetMaximalParameterValue, "defines the maximum value allowed for the first and last parameters of an infinite curve. Default value: 500. VrmlConverter_Curve VrmlConverter_WFRestrictedFace VrmlConverter_WFShape", py::arg("Value"));
cls_VrmlConverter_Drawer.def("MaximalParameterValue", (Standard_Real (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::MaximalParameterValue, "None");
cls_VrmlConverter_Drawer.def("SetIsoOnPlane", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetIsoOnPlane, "enables the drawing of isos on planes. By default there are no isos on planes.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("IsoOnPlane", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::IsoOnPlane, "returns True if the drawing of isos on planes is enabled.");
cls_VrmlConverter_Drawer.def("UIsoAspect", (opencascade::handle<VrmlConverter_IsoAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::UIsoAspect, "Defines the attributes which are used when drawing an U isoparametric curve of a face. Defines the number of U isoparametric curves to be drawn for a single face. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetUIsoAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_IsoAspect> &)) &VrmlConverter_Drawer::SetUIsoAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("VIsoAspect", (opencascade::handle<VrmlConverter_IsoAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::VIsoAspect, "Defines the attributes which are used when drawing an V isoparametric curve of a face. Defines the number of V isoparametric curves to be drawn for a single face. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetVIsoAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_IsoAspect> &)) &VrmlConverter_Drawer::SetVIsoAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("FreeBoundaryAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::FreeBoundaryAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetFreeBoundaryAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetFreeBoundaryAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetFreeBoundaryDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetFreeBoundaryDraw, "enables the drawing the free boundaries By default the free boundaries are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("FreeBoundaryDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::FreeBoundaryDraw, "returns True if the drawing of the free boundaries is enabled.");
cls_VrmlConverter_Drawer.def("WireAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::WireAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetWireAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetWireAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetWireDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetWireDraw, "enables the drawing the wire By default the wire are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("WireDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::WireDraw, "returns True if the drawing of the wire is enabled.");
cls_VrmlConverter_Drawer.def("UnFreeBoundaryAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::UnFreeBoundaryAspect, "The default values are the same default values from Vrml package. These attributes are used by the following algorithms: VrmlConverter_WFShape VrmlConverter_WFDeflectionShape");
cls_VrmlConverter_Drawer.def("SetUnFreeBoundaryAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetUnFreeBoundaryAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SetUnFreeBoundaryDraw", (void (VrmlConverter_Drawer::*)(const Standard_Boolean)) &VrmlConverter_Drawer::SetUnFreeBoundaryDraw, "enables the drawing the unfree boundaries By default the unfree boundaries are drawn.", py::arg("OnOff"));
cls_VrmlConverter_Drawer.def("UnFreeBoundaryDraw", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::UnFreeBoundaryDraw, "returns True if the drawing of the unfree boundaries is enabled.");
cls_VrmlConverter_Drawer.def("LineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::LineAspect, "The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetLineAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("PointAspect", (opencascade::handle<VrmlConverter_PointAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::PointAspect, "None");
cls_VrmlConverter_Drawer.def("SetPointAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_PointAspect> &)) &VrmlConverter_Drawer::SetPointAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("ShadingAspect", (opencascade::handle<VrmlConverter_ShadingAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::ShadingAspect, "The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetShadingAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_ShadingAspect> &)) &VrmlConverter_Drawer::SetShadingAspect, "None", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("DrawHiddenLine", (Standard_Boolean (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DrawHiddenLine, "returns Standard_True if the hidden lines are to be drawn. By default the hidden lines are not drawn.");
cls_VrmlConverter_Drawer.def("EnableDrawHiddenLine", (void (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::EnableDrawHiddenLine, "sets DrawHiddenLine = Standard_True - the hidden lines are drawn.");
cls_VrmlConverter_Drawer.def("DisableDrawHiddenLine", (void (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::DisableDrawHiddenLine, "sets DrawHiddenLine = Standard_False - the hidden lines are not drawn.");
cls_VrmlConverter_Drawer.def("HiddenLineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::HiddenLineAspect, "returns LineAspect for the hidden lines. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetHiddenLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetHiddenLineAspect, "sets LineAspect for the hidden lines.", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def("SeenLineAspect", (opencascade::handle<VrmlConverter_LineAspect> (VrmlConverter_Drawer::*)()) &VrmlConverter_Drawer::SeenLineAspect, "returns LineAspect for the seen lines. The default values are the same default values from Vrml package.");
cls_VrmlConverter_Drawer.def("SetSeenLineAspect", (void (VrmlConverter_Drawer::*)(const opencascade::handle<VrmlConverter_LineAspect> &)) &VrmlConverter_Drawer::SetSeenLineAspect, "sets LineAspect for the seen lines.", py::arg("anAspect"));
cls_VrmlConverter_Drawer.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_Drawer::get_type_name, "None");
cls_VrmlConverter_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_Drawer::get_type_descriptor, "None");
cls_VrmlConverter_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_Drawer::*)() const) &VrmlConverter_Drawer::DynamicType, "None");

// CLASS: VRMLCONVERTER_HLRSHAPE
py::class_<VrmlConverter_HLRShape> cls_VrmlConverter_HLRShape(mod, "VrmlConverter_HLRShape", "HLRShape - computes the presentation of objects with removal of their hidden lines for a specific projector, converts them into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer of Drawer class. This kind of the presentation is converted into IndexedLineSet and if they are defined in Projector into : PerspectiveCamera, OrthographicCamera, DirectionLight, PointLight, SpotLight from Vrml package.");

// Methods
// cls_VrmlConverter_HLRShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_HLRShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_HLRShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_HLRShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_HLRShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_HLRShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_HLRShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_HLRShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_HLRShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_HLRShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_HLRShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &, const opencascade::handle<VrmlConverter_Projector> &)) &VrmlConverter_HLRShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"), py::arg("aProjector"));

// CLASS: VRMLCONVERTER_LINEASPECT
py::class_<VrmlConverter_LineAspect, opencascade::handle<VrmlConverter_LineAspect>, Standard_Transient> cls_VrmlConverter_LineAspect(mod, "VrmlConverter_LineAspect", "qualifies the aspect properties for the VRML conversation of a Curve and a DeflectionCurve .");

// Constructors
cls_VrmlConverter_LineAspect.def(py::init<>());
cls_VrmlConverter_LineAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean>(), py::arg("aMaterial"), py::arg("OnOff"));

// Methods
cls_VrmlConverter_LineAspect.def("SetMaterial", (void (VrmlConverter_LineAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_LineAspect::SetMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_LineAspect.def("Material", (opencascade::handle<Vrml_Material> (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::Material, "None");
cls_VrmlConverter_LineAspect.def("SetHasMaterial", (void (VrmlConverter_LineAspect::*)(const Standard_Boolean)) &VrmlConverter_LineAspect::SetHasMaterial, "defines the necessary of writing own Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_LineAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_LineAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_LineAspect::get_type_name, "None");
cls_VrmlConverter_LineAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_LineAspect::get_type_descriptor, "None");
cls_VrmlConverter_LineAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_LineAspect::*)() const) &VrmlConverter_LineAspect::DynamicType, "None");

// CLASS: VRMLCONVERTER_ISOASPECT
py::class_<VrmlConverter_IsoAspect, opencascade::handle<VrmlConverter_IsoAspect>, VrmlConverter_LineAspect> cls_VrmlConverter_IsoAspect(mod, "VrmlConverter_IsoAspect", "qualifies the aspect properties for the VRML conversation of iso curves .");

// Constructors
cls_VrmlConverter_IsoAspect.def(py::init<>());
cls_VrmlConverter_IsoAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean, const Standard_Integer>(), py::arg("aMaterial"), py::arg("OnOff"), py::arg("aNumber"));

// Methods
cls_VrmlConverter_IsoAspect.def("SetNumber", (void (VrmlConverter_IsoAspect::*)(const Standard_Integer)) &VrmlConverter_IsoAspect::SetNumber, "None", py::arg("aNumber"));
cls_VrmlConverter_IsoAspect.def("Number", (Standard_Integer (VrmlConverter_IsoAspect::*)() const) &VrmlConverter_IsoAspect::Number, "returns the number of U or V isoparametric curves drawn for a single face.");
cls_VrmlConverter_IsoAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_IsoAspect::get_type_name, "None");
cls_VrmlConverter_IsoAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_IsoAspect::get_type_descriptor, "None");
cls_VrmlConverter_IsoAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_IsoAspect::*)() const) &VrmlConverter_IsoAspect::DynamicType, "None");

// CLASS: VRMLCONVERTER_POINTASPECT
py::class_<VrmlConverter_PointAspect, opencascade::handle<VrmlConverter_PointAspect>, Standard_Transient> cls_VrmlConverter_PointAspect(mod, "VrmlConverter_PointAspect", "qualifies the aspect properties for the VRML conversation of a Point Set.");

// Constructors
cls_VrmlConverter_PointAspect.def(py::init<>());
cls_VrmlConverter_PointAspect.def(py::init<const opencascade::handle<Vrml_Material> &, const Standard_Boolean>(), py::arg("aMaterial"), py::arg("OnOff"));

// Methods
cls_VrmlConverter_PointAspect.def("SetMaterial", (void (VrmlConverter_PointAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_PointAspect::SetMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_PointAspect.def("Material", (opencascade::handle<Vrml_Material> (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::Material, "None");
cls_VrmlConverter_PointAspect.def("SetHasMaterial", (void (VrmlConverter_PointAspect::*)(const Standard_Boolean)) &VrmlConverter_PointAspect::SetHasMaterial, "defines the necessary of writing own Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_PointAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_PointAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_PointAspect::get_type_name, "None");
cls_VrmlConverter_PointAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_PointAspect::get_type_descriptor, "None");
cls_VrmlConverter_PointAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_PointAspect::*)() const) &VrmlConverter_PointAspect::DynamicType, "None");

// CLASS: VRMLCONVERTER_PROJECTOR
py::class_<VrmlConverter_Projector, opencascade::handle<VrmlConverter_Projector>, Standard_Transient> cls_VrmlConverter_Projector(mod, "VrmlConverter_Projector", "defines projector and calculates properties of cameras and lights from Vrml ( OrthograpicCamera, PerspectiveCamera, DirectionalLight, PointLight, SpotLight and MatrixTransform ) to display all scene shapes with arbitrary locations for requested the Projection Vector, High Point Direction and the Focus and adds them ( method Add ) to anOSream.");

// Constructors
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"));
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const VrmlConverter_TypeOfCamera>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"), py::arg("Camera"));
cls_VrmlConverter_Projector.def(py::init<const TopTools_Array1OfShape &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const VrmlConverter_TypeOfCamera, const VrmlConverter_TypeOfLight>(), py::arg("Shapes"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"), py::arg("Camera"), py::arg("Light"));

// Methods
cls_VrmlConverter_Projector.def("SetCamera", (void (VrmlConverter_Projector::*)(const VrmlConverter_TypeOfCamera)) &VrmlConverter_Projector::SetCamera, "None", py::arg("aCamera"));
cls_VrmlConverter_Projector.def("Camera", (VrmlConverter_TypeOfCamera (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Camera, "None");
cls_VrmlConverter_Projector.def("SetLight", (void (VrmlConverter_Projector::*)(const VrmlConverter_TypeOfLight)) &VrmlConverter_Projector::SetLight, "None", py::arg("aLight"));
cls_VrmlConverter_Projector.def("Light", (VrmlConverter_TypeOfLight (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Light, "None");
cls_VrmlConverter_Projector.def("Add", (void (VrmlConverter_Projector::*)(Standard_OStream &) const) &VrmlConverter_Projector::Add, "Adds into anOStream if they are defined in Create. PerspectiveCamera, OrthographicCamera, DirectionLight, PointLight, SpotLight with MatrixTransform from VrmlConverter;", py::arg("anOStream"));
cls_VrmlConverter_Projector.def("Projector", (HLRAlgo_Projector (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::Projector, "None");
cls_VrmlConverter_Projector.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_Projector::get_type_name, "None");
cls_VrmlConverter_Projector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_Projector::get_type_descriptor, "None");
cls_VrmlConverter_Projector.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_Projector::*)() const) &VrmlConverter_Projector::DynamicType, "None");

// CLASS: VRMLCONVERTER_SHADEDSHAPE
py::class_<VrmlConverter_ShadedShape> cls_VrmlConverter_ShadedShape(mod, "VrmlConverter_ShadedShape", "ShadedShape - computes the shading presentation of shapes by triangulation algorithms, converts this one into VRML objects and writes (adds) into anOStream. All requested properties of the representation including the maximal chordial deviation are specify in aDrawer. This kind of the presentation is converted into IndexedFaceSet ( VRML ).");

// Methods
// cls_VrmlConverter_ShadedShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_ShadedShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_ShadedShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_ShadedShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_ShadedShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_ShadedShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_ShadedShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_ShadedShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_ShadedShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_ShadedShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"));
cls_VrmlConverter_ShadedShape.def_static("ComputeNormal_", (void (*)(const TopoDS_Face &, Poly_Connect &, TColgp_Array1OfDir &)) &VrmlConverter_ShadedShape::ComputeNormal, "None", py::arg("aFace"), py::arg("pc"), py::arg("Nor"));

// CLASS: VRMLCONVERTER_SHADINGASPECT
py::class_<VrmlConverter_ShadingAspect, opencascade::handle<VrmlConverter_ShadingAspect>, Standard_Transient> cls_VrmlConverter_ShadingAspect(mod, "VrmlConverter_ShadingAspect", "qualifies the aspect properties for the VRML conversation of ShadedShape .");

// Constructors
cls_VrmlConverter_ShadingAspect.def(py::init<>());

// Methods
cls_VrmlConverter_ShadingAspect.def("SetFrontMaterial", (void (VrmlConverter_ShadingAspect::*)(const opencascade::handle<Vrml_Material> &)) &VrmlConverter_ShadingAspect::SetFrontMaterial, "None", py::arg("aMaterial"));
cls_VrmlConverter_ShadingAspect.def("FrontMaterial", (opencascade::handle<Vrml_Material> (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::FrontMaterial, "None");
cls_VrmlConverter_ShadingAspect.def("SetShapeHints", (void (VrmlConverter_ShadingAspect::*)(const Vrml_ShapeHints &)) &VrmlConverter_ShadingAspect::SetShapeHints, "None", py::arg("aShapeHints"));
cls_VrmlConverter_ShadingAspect.def("ShapeHints", (Vrml_ShapeHints (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::ShapeHints, "None");
cls_VrmlConverter_ShadingAspect.def("SetHasNormals", (void (VrmlConverter_ShadingAspect::*)(const Standard_Boolean)) &VrmlConverter_ShadingAspect::SetHasNormals, "defines necessary of a calculation of normals for ShadedShape to more accurately display curved surfaces, pacticularly when smoooth or phong shading is used in VRML viewer. By default False - the normals are not calculated, True - the normals are calculated. Warning: If normals are calculated the resulting VRML file will be substantially lager.", py::arg("OnOff"));
cls_VrmlConverter_ShadingAspect.def("HasNormals", (Standard_Boolean (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::HasNormals, "returns True if the normals are calculating");
cls_VrmlConverter_ShadingAspect.def("SetHasMaterial", (void (VrmlConverter_ShadingAspect::*)(const Standard_Boolean)) &VrmlConverter_ShadingAspect::SetHasMaterial, "defines necessary of writing Material from Vrml into output OStream. By default False - the material is not writing into OStream, True - the material is writing.", py::arg("OnOff"));
cls_VrmlConverter_ShadingAspect.def("HasMaterial", (Standard_Boolean (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::HasMaterial, "returns True if the materials is writing into OStream.");
cls_VrmlConverter_ShadingAspect.def_static("get_type_name_", (const char * (*)()) &VrmlConverter_ShadingAspect::get_type_name, "None");
cls_VrmlConverter_ShadingAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlConverter_ShadingAspect::get_type_descriptor, "None");
cls_VrmlConverter_ShadingAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlConverter_ShadingAspect::*)() const) &VrmlConverter_ShadingAspect::DynamicType, "None");

// CLASS: VRMLCONVERTER_WFDEFLECTIONRESTRICTEDFACE
py::class_<VrmlConverter_WFDeflectionRestrictedFace> cls_VrmlConverter_WFDeflectionRestrictedFace(mod, "VrmlConverter_WFDeflectionRestrictedFace", "WFDeflectionRestrictedFace - computes the wireframe presentation of faces with restrictions by displaying a given number of U and/or V isoparametric curves, converts his into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer of Drawer class (Prs3d). This kind of the presentation is converted into IndexedFaceSet and IndexedLineSet ( VRML ).");

// Methods
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_WFDeflectionRestrictedFace::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_WFDeflectionRestrictedFace::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_WFDeflectionRestrictedFace::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_WFDeflectionRestrictedFace::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_WFDeflectionRestrictedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_WFDeflectionRestrictedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("Add_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFDeflectionRestrictedFace::Add, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("AddUIso_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFDeflectionRestrictedFace::AddUIso, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("AddVIso_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFDeflectionRestrictedFace::AddVIso, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFDeflectionRestrictedFace.def_static("Add_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer, const Standard_Integer, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFDeflectionRestrictedFace::Add, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("DrawUIso"), py::arg("DrawVIso"), py::arg("Deflection"), py::arg("NBUiso"), py::arg("NBViso"), py::arg("aDrawer"));

// CLASS: VRMLCONVERTER_WFDEFLECTIONSHAPE
py::class_<VrmlConverter_WFDeflectionShape> cls_VrmlConverter_WFDeflectionShape(mod, "VrmlConverter_WFDeflectionShape", "WFDeflectionShape - computes the wireframe presentation of compound set of faces, edges and vertices by displaying a given number of U and/or V isoparametric curves, converts this one into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer. This kind of the presentation is converted into IndexedLineSet and PointSet ( VRML ).");

// Methods
// cls_VrmlConverter_WFDeflectionShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_WFDeflectionShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_WFDeflectionShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_WFDeflectionShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_WFDeflectionShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_WFDeflectionShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_WFDeflectionShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_WFDeflectionShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_WFDeflectionShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_WFDeflectionShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_WFDeflectionShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFDeflectionShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"));

// CLASS: VRMLCONVERTER_WFRESTRICTEDFACE
py::class_<VrmlConverter_WFRestrictedFace> cls_VrmlConverter_WFRestrictedFace(mod, "VrmlConverter_WFRestrictedFace", "WFRestrictedFace - computes the wireframe presentation of faces with restrictions by displaying a given number of U and/or V isoparametric curves, converts this one into VRML objects and writes (adds) into anOStream. All requested properties of the representation are specify in aDrawer. This kind of the presentation is converted into IndexedLineSet ( VRML ).");

// Methods
// cls_VrmlConverter_WFRestrictedFace.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_WFRestrictedFace::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_WFRestrictedFace.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_WFRestrictedFace::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_WFRestrictedFace.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_WFRestrictedFace::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_WFRestrictedFace.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_WFRestrictedFace::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_WFRestrictedFace.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_WFRestrictedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_WFRestrictedFace.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_WFRestrictedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_WFRestrictedFace.def_static("Add_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFRestrictedFace::Add, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFRestrictedFace.def_static("AddUIso_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFRestrictedFace::AddUIso, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFRestrictedFace.def_static("AddVIso_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFRestrictedFace::AddVIso, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("aDrawer"));
cls_VrmlConverter_WFRestrictedFace.def_static("Add_", (void (*)(Standard_OStream &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFRestrictedFace::Add, "None", py::arg("anOStream"), py::arg("aFace"), py::arg("DrawUIso"), py::arg("DrawVIso"), py::arg("NBUiso"), py::arg("NBViso"), py::arg("aDrawer"));

// CLASS: VRMLCONVERTER_WFSHAPE
py::class_<VrmlConverter_WFShape> cls_VrmlConverter_WFShape(mod, "VrmlConverter_WFShape", "WFShape - computes the wireframe presentation of compound set of faces, edges and vertices by displaying a given number of U and/or V isoparametric curves converts this one into VRML objects and writes (adds) them into anOStream. All requested properties of the representation are specify in aDrawer. This kind of the presentation is converted into IndexedLineSet and PointSet ( VRML ).");

// Methods
// cls_VrmlConverter_WFShape.def_static("operator new_", (void * (*)(size_t)) &VrmlConverter_WFShape::operator new, "None", py::arg("theSize"));
// cls_VrmlConverter_WFShape.def_static("operator delete_", (void (*)(void *)) &VrmlConverter_WFShape::operator delete, "None", py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator new[]_", (void * (*)(size_t)) &VrmlConverter_WFShape::operator new[], "None", py::arg("theSize"));
// cls_VrmlConverter_WFShape.def_static("operator delete[]_", (void (*)(void *)) &VrmlConverter_WFShape::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlConverter_WFShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlConverter_WFShape.def_static("operator delete_", (void (*)(void *, void *)) &VrmlConverter_WFShape::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlConverter_WFShape.def_static("Add_", (void (*)(Standard_OStream &, const TopoDS_Shape &, const opencascade::handle<VrmlConverter_Drawer> &)) &VrmlConverter_WFShape::Add, "None", py::arg("anOStream"), py::arg("aShape"), py::arg("aDrawer"));


}
