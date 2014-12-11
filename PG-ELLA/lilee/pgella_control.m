function varargout = pgella_control(varargin)
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @pgella_control_OpeningFcn, ...
                   'gui_OutputFcn',  @pgella_control_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before pgella_control is made visible.
function pgella_control_OpeningFcn(hObject, eventdata, handles, varargin)

% Choose default command line output for pgella_control
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% Instantiate PGCommunicator
global rosCommunicator;
rosCommunicator = PGCommunicator(handles);


% Allow edge finding only if Image Processing Toolbox license exists
if ~license('test', 'image_toolbox')
    set(handles.edgeCheckbox, 'Visible', 'off');
end


% --- Outputs from this function are returned to the command line.
function varargout = pgella_control_OutputFcn(hObject, eventdata, handles)
varargout{1} = handles.output;


function orientEdit_CreateFcn(hObject, eventdata, handles)
function posXEdit_CreateFcn(hObject, eventdata, handles)
function posYEdit_CreateFcn(hObject, eventdata, handles)
function posZEdit_CreateFcn(hObject, eventdata, handles)
function leftTurnButton_ButtonDownFcn(hObject, eventdata, handles)
function rightTurnButton_ButtonDownFcn(hObject, eventdata, handles)
function forwardButton_ButtonDownFcn(hObject, eventdata, handles)
function reverseButton_ButtonDownFcn(hObject, eventdata, handles)
function enableCamera(camera_id, handles)
function popupmenu1_CreateFcn(hObject, eventdata, handles)

% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)

global rosCommunicator;
delete(rosCommunicator);
delete(hObject);
