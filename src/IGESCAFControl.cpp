#include <pyOCCT_Common.hpp>

#include <IGESControl_Reader.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESCAFControl_Reader.hxx>
#include <IGESControl_Writer.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_Label.hxx>
#include <IGESCAFControl_Writer.hxx>
#include <Quantity_Color.hxx>
#include <IGESCAFControl.hxx>

PYBIND11_MODULE(IGESCAFControl, mod) {

	// IMPORT
	py::module::import("OCCT.IGESControl");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.XSControl");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.Quantity");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESCAFControl_Reader.hxx
	py::class_<IGESCAFControl_Reader, std::unique_ptr<IGESCAFControl_Reader, Deleter<IGESCAFControl_Reader>>, IGESControl_Reader> cls_IGESCAFControl_Reader(mod, "IGESCAFControl_Reader", "Provides a tool to read IGES file and put it into DECAF document. Besides transfer of shapes (including assemblies) provided by IGESControl, supports also colors and part names IGESCAFControl_Reader reader; Methods for translation of an IGES file: reader.ReadFile('filename'); reader.Transfer(Document); or reader.Perform('filename',doc); Methods for managing reading attributes. Colors reader.SetColorMode(colormode); Standard_Boolean colormode = reader.GetColorMode(); Layers reader.SetLayerMode(layermode); Standard_Boolean layermode = reader.GetLayerMode(); Names reader.SetNameMode(namemode); Standard_Boolean namemode = reader.GetNameMode();");
	cls_IGESCAFControl_Reader.def(py::init<>());
	cls_IGESCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("theWS"));
	cls_IGESCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("theWS"), py::arg("FromScratch"));
	cls_IGESCAFControl_Reader.def("Transfer", (Standard_Boolean (IGESCAFControl_Reader::*)(opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Transfer, "Translates currently loaded IGES file into the document Returns True if succeeded, and False in case of fail", py::arg("theDoc"));
	cls_IGESCAFControl_Reader.def("Perform", (Standard_Boolean (IGESCAFControl_Reader::*)(const TCollection_AsciiString &, opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Perform, "None", py::arg("theFileName"), py::arg("theDoc"));
	cls_IGESCAFControl_Reader.def("Perform", (Standard_Boolean (IGESCAFControl_Reader::*)(const Standard_CString, opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Perform, "Translate IGES file given by filename into the document Return True if succeeded, and False in case of fail", py::arg("theFileName"), py::arg("theDoc"));
	cls_IGESCAFControl_Reader.def("SetColorMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetColorMode, "Set ColorMode for indicate read Colors or not.", py::arg("theMode"));
	cls_IGESCAFControl_Reader.def("GetColorMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const ) &IGESCAFControl_Reader::GetColorMode, "None");
	cls_IGESCAFControl_Reader.def("SetNameMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetNameMode, "Set NameMode for indicate read Name or not.", py::arg("theMode"));
	cls_IGESCAFControl_Reader.def("GetNameMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const ) &IGESCAFControl_Reader::GetNameMode, "None");
	cls_IGESCAFControl_Reader.def("SetLayerMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetLayerMode, "Set LayerMode for indicate read Layers or not.", py::arg("theMode"));
	cls_IGESCAFControl_Reader.def("GetLayerMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const ) &IGESCAFControl_Reader::GetLayerMode, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESCAFControl_Writer.hxx
	py::class_<IGESCAFControl_Writer, std::unique_ptr<IGESCAFControl_Writer, Deleter<IGESCAFControl_Writer>>, IGESControl_Writer> cls_IGESCAFControl_Writer(mod, "IGESCAFControl_Writer", "Provides a tool to write DECAF document to the IGES file. Besides transfer of shapes (including assemblies) provided by IGESControl, supports also colors and part names IGESCAFControl_Writer writer(); Methods for writing IGES file: writer.Transfer (Document); writer.Write('filename') or writer.Write(OStream) or writer.Perform(Document,'filename'); Methods for managing the writing of attributes. Colors writer.SetColorMode(colormode); Standard_Boolean colormode = writer.GetColorMode(); Layers writer.SetLayerMode(layermode); Standard_Boolean layermode = writer.GetLayerMode(); Names writer.SetNameMode(namemode); Standard_Boolean namemode = writer.GetNameMode();");
	cls_IGESCAFControl_Writer.def(py::init<>());
	cls_IGESCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
	cls_IGESCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));
	cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Writer::Transfer, "Transfers a document to a IGES model Returns True if translation is OK", py::arg("doc"));
	cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const TDF_LabelSequence &)) &IGESCAFControl_Writer::Transfer, "Transfers labels to a IGES model Returns True if translation is OK", py::arg("labels"));
	cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const TDF_Label &)) &IGESCAFControl_Writer::Transfer, "Transfers label to a IGES model Returns True if translation is OK", py::arg("label"));
	cls_IGESCAFControl_Writer.def("Perform", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &)) &IGESCAFControl_Writer::Perform, "None", py::arg("doc"), py::arg("filename"));
	cls_IGESCAFControl_Writer.def("Perform", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const Standard_CString)) &IGESCAFControl_Writer::Perform, "Transfers a document and writes it to a IGES file Returns True if translation is OK", py::arg("doc"), py::arg("filename"));
	cls_IGESCAFControl_Writer.def("SetColorMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetColorMode, "Set ColorMode for indicate write Colors or not.", py::arg("colormode"));
	cls_IGESCAFControl_Writer.def("GetColorMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const ) &IGESCAFControl_Writer::GetColorMode, "None");
	cls_IGESCAFControl_Writer.def("SetNameMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetNameMode, "Set NameMode for indicate write Name or not.", py::arg("namemode"));
	cls_IGESCAFControl_Writer.def("GetNameMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const ) &IGESCAFControl_Writer::GetNameMode, "None");
	cls_IGESCAFControl_Writer.def("SetLayerMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetLayerMode, "Set LayerMode for indicate write Layers or not.", py::arg("layermode"));
	cls_IGESCAFControl_Writer.def("GetLayerMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const ) &IGESCAFControl_Writer::GetLayerMode, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IGESCAFControl.hxx
	py::class_<IGESCAFControl, std::unique_ptr<IGESCAFControl, Deleter<IGESCAFControl>>> cls_IGESCAFControl(mod, "IGESCAFControl", "Provides high-level API to translate IGES file to and from DECAF document");
	cls_IGESCAFControl.def(py::init<>());
	cls_IGESCAFControl.def_static("DecodeColor_", (Quantity_Color (*)(const Standard_Integer)) &IGESCAFControl::DecodeColor, "Provides a tool for writing IGES file Converts IGES color index to CASCADE color", py::arg("col"));
	cls_IGESCAFControl.def_static("EncodeColor_", (Standard_Integer (*)(const Quantity_Color &)) &IGESCAFControl::EncodeColor, "Tries to Convert CASCADE color to IGES color index If no corresponding color defined in IGES, returns 0", py::arg("col"));


}
